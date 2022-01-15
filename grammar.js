const precedences = require("./grammar/precedences.js");

const newline = "\n";
const terminator = choice(newline, ";");
const digits = token(/[0-9]+/);
const hex_digit = /[0-9a-fA-F]/;
const decimal_number = choice(/[0-9]+\.[0-9]*/, /[0-9]*\.[0-9]+/);

module.exports = grammar({
  name: "wolfram",

  externals: (_) => [],

  extras: ($) => [$.comment, /[\s\f\uFEFF\u2060\u200B]|\\\r?\n/],

  confilcts: (_) => [],

  supertypes: ($) => [$.atomic],

  word: ($) => $.identifier,

  rules: {
    source_file: ($) => repeat(seq($.expression, terminator)),

    expression: ($) => choice($.atomic),

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
        $.number
        // $.out_expression,
        // $.slot_expression,
        // $.string,
        // $.pattern_blank_expression
      ),

    // =================
    // ---- Numbers ----
    // =================

    number: (_) => {
      const exponent = prec(-1, seq("*^", optional(choice("+", "-")), digits));
      const precision = seq(choice("``", "`"), choice(decimal_number, digits));

      return prec.right(
        //precedences.number.precedence,
        choice(
          seq(
            choice(digits, decimal_number),
            optional(precision),
            optional(exponent)
          )
        )
      );
    },

    // =========================
    // ---- Builtin Symbols ----
    // =========================

    builtin_symbol: (_) =>
      choice(
        token("True"),
        token("False"),
        token("Null"),
        token("I"),
        token("ImaginaryI"),
        token("ImaginaryJ"),
        token("ExponentialE"),
        token("Pi"),
        token("\\[Pi]")
      ),

    // =================
    // ---- Symbols ----
    // =================

    scoped_symbol: ($) => {
      // const op = precedences.symbol;
      return prec.right(
        1000,
        seq(
          field("context", seq(optional("`"), repeat1(seq($.identifier, "`")))),
          field("name", $.identifier)
        )
      );
    },

    _symbol: ($) => {
      return prec(precedences.symbol.precedence, $.identifier);
    },

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

      const ident_start =
        "(" + escaped_letters + "|" + /[\$\p{L}]/.source + ")";
      const ident_end =
        "(" + escaped_letters + "|" + /[\$\p{L}\d]/.source + ")*";
      return token(new RegExp(ident_start + ident_end));
    },
  },
});

function precedented(expr) {}
