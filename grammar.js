const precedences = require("./grammar/precedences.js");

const newline = "\n";
const terminator = choice(newline, ";");

const digit = token(/[0-9]/);
const digits = token(/[0-9]+/);
const hex_digit = /[0-9a-fA-F]/;
const decimal_number = choice(/[0-9]+\.[0-9]*/, /[0-9]*\.[0-9]+/);
const exponent = prec(-1, seq("*^", optional(choice("+", "-")), digits));
const precision = seq(choice("``", "`"), choice(decimal_number, digits));

const unicode_escape = seq(
  "\\",
  ":",
  hex_digit,
  hex_digit,
  hex_digit,
  hex_digit
);
const escape_sequence = choice(
  "\\",
  seq("\\", choice(/['"abfrntv\\]/, /\d{3}/, /\r?\n/)),
  unicode_escape
);

const script = /Script(Capital)?[A-Z]/;
const gothic = /Gothic(Capital)?[A-Z]/;
const struck = /DoubleStruck(Capital)?[A-Z]/;
const formal = /Formal(Capital)?[A-Z]/;
const other =
  /(Capital)?(AE|AAcute|ABar|AGrave|ACup|AHat|ARing|ADoubleDot|ATilde|CAcute|CHacek|CCedilla|Eth|DHacek|EHacek|EAcute|EBar|EGrave|ECup|EHat|EDoubleDot|IAcute|IGrave|ICup|IHat|IDoubleDot|LSlash|NTilde|NHacek|OAcute|OGrave|OE|OHat|ODoubleDot|ODoubleAcute|OTilde|OSlash|RHacek|SHacek|Thorn|THacek|URing|UAcute|UGrave|UHat|UDoubleDot|UDoubleAcute|YAcute|ZHacek)/;
const greek =
  /(Capital|FormalCapital|Formal)?(Alpha|Beta|Gamma|Delta|Epsilon|Zeta|Eta|Theta|Iota|Kappa|Lambda|Mu|Pi|Nu|Xi|Omicron|Rho|Sigma|Tau|Phi|Chi|Psi|Omega|Stigma|Digamma|Koppa|Sampi|Upsilon)/;
const greek2 =
  /(CurlyEpsilon|CurlyCapitalUpsilon|CurlyTheta|CurlyKappa|CurlyPi|CurlyRho|CurlyPhi|FinalSigma|FormalCurlyEpsilon|FormalFinalSigma|FormalCurlyPhi|FormalCurlyTheta|FormalCurlyCapitalUpsilon|FormalCurlyPi|FormalCurlyKappa|FormalCurlyRho)/;
const misc =
  /(Aleph|Bet|Gimel|Dalet|Hacek|Florin|Micro|Mho|Angstrom|HBar|Cent|Sterling|Yen|Degree|EmptySet|EmptySet|DoubledPi|DoubledGamma|WeierstrassP|ExponentialE|ImaginaryI|ImaginaryJ|FiLigature|FlLigature|DotlessI|DotlessJ|SZ|YDoubleDot|ScriptDotlessI|ScriptDotlessJ)/;
const escaped_letters =
  "(" +
  /\\\[/.source +
  "(" +
  [script, gothic, struck, formal, other, greek, greek2, misc]
    .map((rg) => {
      return "(" + rg.source + ")";
    })
    .join("|") +
  ")" +
  /\]/.source +
  ")";
const ident_start = "(" + escaped_letters + "|" + /[\$\p{L}]/.source + ")";
const ident_end = "(" + escaped_letters + "|" + /[\$\p{L}\d]/.source + ")*";
const ident = new RegExp(ident_start + ident_end);
const context = new RegExp(
  /`?/.source + "(" + ident.source + /`/.source + ")+"
);
const string_inner = repeat(
  choice(token.immediate(prec(1, /[^\\"\n]+/)), escape_sequence)
);

module.exports = grammar({
  name: "wolfram",

  externals: (_) => [],

  extras: ($) => [
    $.comment,
    // /[\s\f\uFEFF\u2060\u200B]|\\\r?\n/
    /\s/,
  ],

  conflicts: ($) => [[$.span], [$.pattern]],

  supertypes: ($) => [$.atomic, $.expression],

  word: ($) => $.identifier,

  rules: {
    source_file: ($) => repeat($.expression_statement),

    // Items that only make sence on their own, not inside other expression.
    expression_statement: ($) =>
      precedented(
        precedences.compound_expression,
        seq(
          choice(
            $.expression,
            $.unset
            //$.get_statement
          ),
          newline
        )
      ),

    get_statement: ($) =>
      seq("<<", field("name", seq($._symbol, optional("`")))),

    expression: ($) =>
      choice(
        $.atomic,
        $.message_name,
        $.assignment,
        $.tag_assigment,
        $.augmented_assignment,
        $.binary_operation,
        $.comparison_operation,
        $.unary_operation,
        //$.implicit_times,
        $.call,
        $.subscript,
        $.pure_function,
        // $.arrow_function,
        $.list,
        $.association,
        $.span,
        $.pattern,
        $.pattern_test,
        $.condition,
        $.parenthesized,
        $.compound,
        $._special
      ),

    compound: ($) =>
      precedented(
        precedences.compound_expression,
        seq(repeat1(seq($.expression, ";")), $.expression, optional(";"))
      ),

    parenthesized: ($) => seq("(", $.expression, ")"),

    // =======================================================================
    // ---- Special ----------------------------------------------------------
    // =======================================================================

    _special: ($) =>
      choice(
        $.return_statement,
        $.break_statement,
        $.continue_statement,
        $.goto_statement,
        $.label_statement,
        $.do_block,
        $.while_block,
        $.for_block,
        $.if_block,
        $.switch_block,
        $.which_block,
        $.module_block
      ),

    return_statement: ($) => seq("Return", "[", optional($.expression), "]"),

    break_statement: (_) => seq("Break", "[", "]"),

    continue_statement: (_) => seq("Continue", "[", "]"),

    goto_statement: ($) => seq("Goto", "[", field("tag", $.expression), "]"),

    label_statement: ($) => seq("Label", "[", field("tag", $.expression), "]"),

    do_block: ($) =>
      seq(
        "Do",
        "[",
        $.expression,
        ",",
        choice($.integer, repeat1($.iter_list)),
        "]"
      ),

    while_block: ($) =>
      seq(
        "While",
        "[",
        field("test", $.expression),
        ",",
        field("body", $.expression),
        "]"
      ),

    for_block: ($) =>
      seq(
        "For",
        "[",
        field("start", $.expression),
        ",",
        field("test", $.expression),
        ",",
        field("incr", $.expression),
        ",",
        field("body", $.expression),
        "]"
      ),

    iter_list: ($) => {
      const iter = field("iter", $.expression);
      const from = field("from", $.expression);
      const to = field("to", $.expression);
      const step = field("step", $.expression);
      return seq(
        "{",
        choice(
          // {i,imax}
          seq(iter, ",", to),
          // {i,imin,imax}
          seq(iter, ",", from, ",", to),
          // {i,imin,imax,di}
          seq(iter, ",", from, ",", to, ",", step)
        ),
        "}"
      );
    },

    if_block: ($) => {
      const c = field("condition", $.expression);
      const t = field("true", $.expression);
      const f = field("false", $.expression);
      const u = field("other", $.expression);

      return choice(
        seq("If", "[", c, ",", t, "]"),
        seq("If", "[", c, ",", t, ",", f, "]"),
        seq("If", "[", c, ",", t, ",", f, ",", u, "]")
      );
    },

    switch_block: ($) =>
      seq(
        "Switch",
        "[",
        field("expr", $.expression),
        repeat1(
          seq(
            ",",
            field("form", $.expression),
            ",",
            field("value", $.expression)
          )
        ),
        "]"
      ),

    which_block: ($) =>
      seq(
        "Which",
        "[",
        seq(field("test", $.expression), ",", field("value", $.expression)),
        repeat(
          seq(
            ",",
            field("test", $.expression),
            ",",
            field("value", $.expression)
          )
        ),
        "]"
      ),

    module_block: ($) =>
      seq(
        field("block", choice("Module", "Block")),
        "[",
        field("locals", $.list),
        ",",
        field("body", $.expression),
        "]"
      ),

    // =======================================================================
    // ---- Operators --------------------------------------------------------
    // =======================================================================

    // ==========================
    // ---- Binary Operators ----
    // ==========================

    binary_operation: ($) => {
      const table = [
        [precedences.infix.plus, "+"],
        [precedences.infix.minus, "-"],
        [precedences.infix.times, "*"],
        [precedences.infix.divide, "/"],
        [precedences.infix.power, "^"],
        [precedences.infix.prefix_apply, "@"],
        [precedences.infix.apply, "@@"],
        [precedences.apply_level_one, "@@@"],
        [precedences.infix.map, "/@"],
        [precedences.map_all, "//@"],
        [precedences.infix.non_commutative_multiply, "**"],
        [precedences.infix.dot, "."],
        [precedences.infix.rule, "->"],
        [precedences.infix.rule_delayed, ":>"],
        [precedences.infix.replace_all, "/."],
        [precedences.infix.replace_repeated, "//."],
        [precedences.infix.postfix_apply, "//"],
        [precedences.infix.string_expression, "<>"],
      ];
      return choice(
        ...table.map(([p, op]) => {
          return precedented(
            p,
            seq(
              field("lhs", $.expression),
              field("operator", op),
              field("rhs", $.expression)
            )
          );
        })
      );
    },

    // implicit_times: ($) =>
    //   prec.dynamic(
    //     -1,
    //     seq(
    //       field("lhs", $.expression),
    //       field("operator", alias(token(/\s+/), "*")),
    //       field("rhs", $.expression)
    //     )
    //   ),

    comparison_operation: ($) => {
      const table = [
        [precedences.comparison.less, "<"],
        [precedences.comparison.less_equal, "<="],
        [precedences.comparison.greater, ">"],
        [precedences.comparison.greater_equal, ">="],
        [precedences.comparison.equal, "=="],
        [precedences.comparison.sameq, "==="],
        [precedences.comparison.unequal, "!="],
        [precedences.comparison.unsameq, "=!="],
        [precedences.or, "||"],
        [precedences.and, "&&"],
      ];
      return choice(
        ...table.map(([p, op]) => {
          return precedented(
            p,
            seq(
              field("lhs", $.expression),
              field("operator", op),
              field("rhs", $.expression)
            )
          );
        })
      );
    },

    unary_operation: ($) => choice($._prefix_operation, $._postfix_operation),

    _prefix_operation: ($) => {
      const table = [
        [precedences.prefix.not, "-"],
        [precedences.prefix.plus, "+"],
        [precedences.prefix.decrement, "--"],
        [precedences.prefix.increment, "++"],
      ];
      return choice(
        ...table.map(([p, op]) => {
          return precedented(
            p,
            seq(field("operator", op), field("expr", $.expression))
          );
        })
      );
    },

    _postfix_operation: ($) => {
      const table = [
        [precedences.postfix.repeated, ".."],
        [precedences.postfix.repeated_null, "..."],
        [precedences.postfix.decrement, "--"],
        [precedences.postfix.increment, "++"],
        [precedences.postfix.derivative, token(/'+/)],
        [precedences.postfix.factorial, "!"],
        [precedences.postfix.double_factorial, "!!"],
      ];

      return choice(
        ...table.map(([p, op]) => {
          return precedented(
            p,
            seq(field("expr", $.expression), field("operator", op))
          );
        })
      );
    },

    // =======================================================================
    // ---- Assignments ------------------------------------------------------
    // =======================================================================

    tag_assigment: ($) =>
      precedented(
        precedences.tag_set,
        seq(field("tag", $.expression), "/:", $.assignment)
      ),

    /**
     * An assignment operation of the form: `expr1 (=, :=, ^=, ^:=) expr2`, or
     * a tag-set: `symb /: expr1 (=, :=, ^=, ^:=) expr2`.
     */
    assignment: ($) => {
      const table = [
        [precedences.assignment.set, "="],
        [precedences.assignment.set_delayed, ":="],
        [precedences.assignment.up_set, "^="],
        [precedences.assignment.up_set_delayed, "^:="],
      ];
      return choice(
        ...table.map(([p, op]) => {
          return precedented(
            p,
            seq(
              field("lhs", $.expression),
              field("operator", op),
              field("rhs", $.expression)
            )
          );
        })
      );
    },

    unset: ($) =>
      precedented(
        precedences.unset,
        seq(
          field("tag", optional(seq($.expression, "/:"))),
          field("name", $.expression),
          field("operator", "=.")
        )
      ),

    /**
     * An augmented assignment operation of the form: `expr1 (+, -, *, /)= expr2`.
     * These all have same precedence and right-associativity.
     */
    augmented_assignment: ($) => {
      const table = [
        [precedences.augmented_assignment.add_to, "+="],
        [precedences.augmented_assignment.times_by, "*="],
        [precedences.augmented_assignment.divide_by, "/="],
        [precedences.augmented_assignment.subtract_from, "-="],
      ];

      return choice(
        ...table.map(([p, op]) => {
          return precedented(
            p,
            seq(
              field("lhs", $.expression),
              field("operator", op),
              field("rhs", $.expression)
            )
          );
        })
      );
    },

    // =======================================================================
    // ---- Functions, Calls, Subscripts, Bracketed --------------------------
    // =======================================================================

    // A function call: `F[x1,x2,...]`.
    call: ($) =>
      precedented(
        precedences.call,
        seq(
          field("head", $.expression),
          field("arguments", seq("[", optional($.argument_list), "]"))
        )
      ),

    // A subscript statement: `F[[args]]`.
    subscript: ($) =>
      precedented(
        precedences.part,
        seq(
          field("head", $.expression),
          field("arguments", seq("[", "[", optional($.argument_list), "]", "]"))
        )
      ),

    //A function definition of the form `expr&`.
    pure_function: ($) =>
      precedented(
        precedences.pure_function,
        seq(field("body", $.expression), "&")
      ),

    // A function definition of the form expr |-> expr2.
    // expr1 |-> expr2 === Function[expr1,expr2]; e |-> (e |-> e)
    arrow_function: ($) =>
      precedented(
        precedences.arrow_function,
        seq(field("argument", $.expression), "->", field("value", $.expression))
      ),

    // Expression like: { e1, e2, ..., en }
    list: ($) =>
      precedented(
        precedences.bracketed.list,
        seq(
          "{",
          optional(seq($.expression, repeat(seq(",", $.expression)))),
          "}"
        )
      ),

    // Expression like: < | e1, e2, ..., en | >
    association: ($) =>
      precedented(
        precedences.bracketed.association,
        seq(
          "<|",
          optional(seq($.expression, repeat(seq(",", $.expression)))),
          "|>"
        )
      ),

    argument_list: ($) => seq($.expression, repeat(seq(",", $.expression))),

    span: ($) =>
      precedented(
        precedences.span,
        seq(
          field("start", optional($.expression)),
          ";;",
          optional(seq(field("skip", $.expression), ";;")),
          field("end", optional($.expression))
        )
      ),

    // =======================================================================
    // ---- Patterns ---------------------------------------------------------
    // =======================================================================

    // Pattern expression: symb:expr or symb:patt:expr
    pattern: ($) =>
      choice(
        precedented(
          precedences.pattern.pattern,
          seq(field("symbol", $._symbol), ":", field("pattern", $.expression))
        ),
        precedented(
          precedences.pattern.optional,
          seq(
            field("pattern", $.expression),
            ":",
            field("default", $.expression)
          )
        )
      ),

    pattern_test: ($) =>
      precedented(
        precedences.pattern.test,
        seq(field("pattern", $.expression), "?", field("test", $.expression))
      ),

    condition: ($) =>
      precedented(
        precedences.pattern.condition,
        seq(field("pattern", $.expression), "/;", field("test", $.expression))
      ),

    // ==================
    // ---- Messages ----
    // ==================

    message_name: ($) => {
      const sym = field("symbol", $._symbol);
      const tag = field("tag", choice($._symbol, $.string));
      const lang = field("lang", choice($._symbol, $.string));
      return precedented(
        precedences.message_name,
        choice(seq(sym, "::", tag), seq(sym, "::", tag, "::", lang))
      );
    },

    // =======================================================================
    // ---- Atomics ----------------------------------------------------------
    // =======================================================================

    atomic: ($) =>
      choice(
        $.scoped_symbol,
        $._symbol,
        $.builtin_symbol,
        // $.true,
        // $.false,
        // $.null,
        $._number,
        $.out,
        $.slot,
        $.string,
        $.pattern_blank
      ),

    // ========================
    // ---- Slots and Outs ----
    // ========================

    out: ($) => {
      const number_ = alias(token.immediate(digits), $.integer);
      return precedented(
        precedences.out,
        choice("%", /%+/, seq("%", field("tag", number_)))
      );
    },

    slot: ($) => {
      const number_ = alias(token.immediate(digits), $.integer);
      const ident_ = alias(token.immediate(ident), $.identifier);
      const context_ = alias(token.immediate(context), $.context);
      const string_ = alias(
        token(seq(token.immediate('"'), string_inner, '"')),
        $.string
      );

      return precedented(
        precedences.slot,
        choice(
          "#",
          "##",
          seq(
            "#",
            field(
              "tag",
              choice(number_, string_, ident_, context_, seq(context_, ident_))
            )
          ),
          seq("##", field("tag", number_))
        )
      );
    },

    // =================
    // ---- Strings ----
    // =================

    string: (_) => {
      const op = precedences.string;
      return op.associativity(
        op.precedence,
        token(
          seq(
            '"',
            repeat(
              choice(token.immediate(prec(1, /[^\\"\n]+/)), escape_sequence)
            ),
            '"'
          )
        )
      );
    },

    // =================
    // ---- Numbers ----
    // =================

    _number: ($) =>
      choice(
        $.integer,
        $.float
        /*$.number_in_base*/
      ),

    integer: (_) =>
      precedented(precedences.number, choice(seq(digits, optional(exponent)))),

    float: (_) =>
      precedented(
        precedences.number,
        choice(
          seq(decimal_number, optional(precision), optional(exponent)),
          seq(choice(digits), precision, optional(exponent))
        )
      ),

    number_in_base: (_) => {
      const _digit_in_any_base = choice(digit, /[a-zA-Z]/);
      const _number_in_base = seq(
        "^^",
        choice(
          seq(
            repeat1(_digit_in_any_base),
            optional(seq(".", repeat(_digit_in_any_base)))
          ),
          seq(
            optional(seq(repeat(_digit_in_any_base), ".")),
            repeat1(_digit_in_any_base)
          )
        )
      );

      return precedented(
        precedences.number,
        seq(digits, _number_in_base, optional(precision), optional(exponent))
      );
    },

    // =========================
    // ---- Builtin Symbols ----
    // =========================

    builtin_symbol: (_) =>
      choice(
        token("True"),
        token("False"),
        token("All"),
        token("Null"),
        token("I"),
        token("ImaginaryI"),
        token("ImaginaryJ"),
        token("ExponentialE"),
        token("Pi"),
        token("\\[Pi]")
      ),

    // ================
    // ---- Blanks ----
    // ================

    pattern_blank: ($) => {
      return precedented(
        precedences.blank,
        choice(
          $._blank,
          $._blank_dot,
          $._symbol_post_blank,
          $._symbol_post_blank_dot,
          $._symbol_pre_blank
        )
      );
    },

    _blank: (_) => precedented(precedences.blank, token(/_{1,3}/)),

    _blank_dot: (_) => precedented(precedences.blank, token(/_\./)),

    _symbol_post_blank: ($) =>
      precedented(
        precedences.blank,
        seq(choice($._symbol, $.scoped_symbol), token.immediate(/_{1,3}/))
      ),

    _symbol_pre_blank: ($) => {
      const op = precedences.blank;
      return op.associativity(
        op.precedence,
        choice(
          seq(
            /_{1,3}/,
            field("context", alias(token.immediate(context), $.context)),
            field("name", alias(token.immediate(ident), $.identifier))
          ),
          seq(
            /_{1,3}/,
            field("name", alias(token.immediate(ident), $.identifier))
          )
        )
      );
    },

    _symbol_post_blank_dot: ($) =>
      precedented(
        precedences.blank,
        seq(choice($._symbol, $.scoped_symbol), token.immediate(/_\./))
      ),
    // =================
    // ---- Symbols ----
    // =================

    scoped_symbol: ($) =>
      precedented(
        precedences.symbol,
        seq(
          field("context", $.context),
          field("name", alias(token.immediate(ident), $.identifier))
        )
      ),

    context: (_) => precedented(precedences.symbol, context),

    _symbol: ($) => precedented(precedences.symbol, $.identifier),

    comment: (_) => {
      const non_comment_chars = /[^((\(\*)|(\*\)))]*/;
      const single = /\(\*[^((\(\*)|(\*\)))]*\*\)/;
      return seq(
        "(*",
        non_comment_chars,
        repeat(seq(single, non_comment_chars)),
        "*)"
      );
    },

    identifier: (_) => {
      return token(ident);
    },
  },
});

function precedented(obj, expr) {
  return obj.associativity(obj.precedence, expr);
}
