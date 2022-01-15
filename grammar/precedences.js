class Delimiters {
  constructor(left, right) {
    this.left = left;
    this.right = right;
  }
}

function make_precedences() {
  let i = 0;
  let next = () => {
    i++;
    return i * 10;
  };
  const operators = {};
  operators.fake = {};
  operators.prefix = {};
  operators.pattern = {};
  operators.assignment = {};
  operators.augmented_assignment = {};
  operators.comparison = {};
  operators.bracketed = {};
  operators.infix = {};
  operators.postfix = {};
  operators.linear_syntax = {};
  operators.fake.prefix = {};

  operators.bracketed.association = {
    precedence: -10,
    associativity: prec,
    delimiters: [
      new Delimiters("<|", "|>"),
      new Delimiters("\uF113", "\uF114"),
      new Delimiters("\\[LeftAssociation]", "\\[RightAssociation]"),
    ],
  };
  operators.bracketed.angle_bracket = {
    precedence: -10,
    associativity: prec,
    delimiters: [
      new Delimiters("\u2329", "\u232a"),
      new Delimiters("\\[LeftAngleBracket]", "\\[RightAngleBracket]"),
    ],
  };
  operators.bracketed.floor = {
    precedence: -10,
    associativity: prec,
    delimiters: [
      new Delimiters("\u230A", "\u230B"),
      new Delimiters("\\[LeftFloor]", "\\[RightFloor]"),
    ],
  };
  operators.bracketed.ceiling = {
    precedence: -10,
    associativity: prec,
    delimiters: [
      new Delimiters("\u2308", "\u2309"),
      new Delimiters("\\[LeftCeiling]", "\\[RightCeiling]"),
    ],
  };
  operators.bracketed.bracketing_bar = {
    precedence: -10,
    associativity: prec,
    delimiters: [
      new Delimiters("\uF603", "\uF604"),
      new Delimiters("\\[LeftBracketingBar]", "\\[RightBracketingBar]"),
    ],
  };
  operators.bracketed.double_bracketing_bar = {
    precedence: -10,
    associativity: prec,
    delimiters: [
      new Delimiters("\uF605", "\uF606"),
      new Delimiters(
        "\\[RightDoubleBracketingBar]",
        "\\[RightDoubleBracketingBar]"
      ),
    ],
  };

  operators.lowest = { precedence: 0, associativity: prec.left, tokens: null };
  operators.comma = {
    precedence: next(),
    associativity: prec.left,
    tokens: [","],
  };
  operators.invisible_comma = {
    precedence: operators.comma.precedence,
    associativity: prec,
    tokens: ["\\[InvisibleComma]", "\uF765"],
    info: "\\[InvisibleComma] is by default not visible on display, but is interpreted on input as an ordinary comma. ",
  };
  operators.compound_expression = {
    precedence: next(),
    associativity: prec.left,
    tokens: [";"],
  };
  operators.infix.put = {
    precedence: next(),
    associativity: prec.left,
    tokens: [">>"],
  };
  operators.infix.put_append = {
    precedence: operators.infix.put.precedence,
    associativity: prec.left,
    tokens: [">>>"],
  };
  operators.assignment.set = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["="],
  };
  operators.assignment.set_delayed = {
    precedence: operators.assignment.set.precedence,
    associativity: prec.right,
    tokens: [":="],
  };
  operators.assignment.up_set = {
    precedence: operators.assignment.set.precedence,
    associativity: prec.right,
    tokens: ["^="],
  };
  operators.assignment.up_set_delayed = {
    precedence: operators.assignment.set.precedence,
    associativity: prec.right,
    tokens: ["^:="],
  };
  operators.unset = {
    precedence: operators.assignment.set.precedence,
    associativity: prec.right,
    tokens: ["=."],
  };
  operators.arrow_function = {
    precedence: operators.assignment.set.precedence,
    associativity: prec.right,
    tokens: ["|->", "\\[Function]"],
  };
  operators.tag_set = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["/:"],
  };
  operators.infix.because = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2235"],
  };
  operators.infix.therefore = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["\u2234"],
  };
  operators.vertical_separator = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uf432"],
  };
  operators.infix.postfix_apply = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["//"],
  };
  operators.infix.apply_to = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["//="],
  };
  operators.colon = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2236"],
  };
  operators.pure_function = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["&"],
  };
  operators.augmented_assignment.add_to = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["+="],
  };
  operators.augmented_assignment.times_by = {
    precedence: operators.augmented_assignment.add_to.precedence,
    associativity: prec.right,
    tokens: ["*="],
  };
  operators.augmented_assignment.subtract_from = {
    precedence: operators.augmented_assignment.add_to.precedence,
    associativity: prec.right,
    tokens: ["-="],
  };
  operators.augmented_assignment.divide_by = {
    precedence: operators.augmented_assignment.add_to.precedence,
    associativity: prec.right,
    tokens: ["/="],
  };
  operators.infix.replace_all = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["/."],
  };
  operators.infix.replace_repeated = {
    precedence: operators.infix.replace_all.precedence,
    associativity: prec.left,
    tokens: ["//."],
  };
  operators.infix.rule = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["->", "\uf522", "\\[Rule]"],
  };
  operators.infix.rule_delayed = {
    precedence: operators.infix.rule.precedence,
    associativity: prec,
    tokens: [":>", "\uf51f", "\\[RuleDelayed]"],
  };
  operators.infix.two_way_rule = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["<->", "\u2216", "\\[TwoWayRule]"],
  };
  operators.pattern.condition = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["/;"],
  };
  operators.infix.string_expression = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["~~", "\u2248"],
  };
  operators.pattern.optional = {
    precedence: next(),
    associativity: prec.left,
    tokens: [":"],
  };
  operators.pattern.pattern = {
    precedence: next(),
    associativity: prec.left,
    tokens: [":"],
  };
  operators.infix.alternatives = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["|"],
  };
  operators.postfix.repeated = {
    precedence: next(),
    associativity: prec.left,
    tokens: [".."],
  };
  operators.postfix.repeated_null = {
    precedence: operators.postfix.repeated.precedence,
    associativity: prec,
    tokens: ["..."],
  };
  operators.infix.such_that = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["\\[SuchThat]", "\u220d"],
  };
  operators.infix.up_tee = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u22a5", "\\[UpTee]"],
  };
  operators.infix.down_tee = {
    precedence: operators.infix.up_tee.precedence,
    associativity: prec,
    tokens: ["\u22a4", "\\[DownTee]"],
  };
  operators.infix.left_tee = {
    precedence: operators.infix.up_tee.precedence,
    associativity: prec,
    tokens: ["\u22a3", "\\[LeftTee]"],
  };
  operators.infix.double_left_tee = {
    precedence: operators.infix.up_tee.precedence,
    associativity: prec,
    tokens: ["\u2ae4", "\\[DoubleLeftTee]"],
  };
  operators.infix.perpendicular = {
    precedence: operators.infix.up_tee.precedence,
    associativity: prec,
    tokens: ["\u27c2", "\\[Perpendicular]"],
  };
  operators.infix.right_tee = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["\u22a2", "\\[RightTee]"],
  };
  operators.infix.double_right_tee = {
    precedence: operators.infix.right_tee.precedence,
    associativity: prec,
    tokens: ["\u22a8", "\\[DoubleRightTee]"],
  };
  operators.conditioned = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uf3d3", "\\[Conditioned]"],
  };
  operators.implies = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["\\[Implies]", "\uf523"],
  };
  operators.round_implies = {
    precedence: operators.implies.precedence,
    associativity: prec,
    tokens: ["\u2970", "\\[RoundImplies]"],
  };
  operators.equivalent = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u29e6", "\\[Equivalent]"],
  };
  operators.or = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["||", "\u2228", "\\[Or]"],
  };
  operators.nor = {
    precedence: operators.or.precedence,
    associativity: prec,
    tokens: ["\u22bd", "\\[Nor]"],
  };
  operators.xor = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u22bb", "\\[Xor]"],
  };
  operators.xnor = {
    precedence: operators.xor.precedence,
    associativity: prec,
    tokens: ["\uf4a2", "\\[Xnor]"],
  };
  operators.and = {
    precedence: next(),
    associativity: prec,
    tokens: ["&&", "\u2227", "\\[And]"],
  };
  operators.nand = {
    precedence: operators.and.precedence,
    associativity: prec,
    tokens: ["\u22bc", "\\[Nand]"],
  };
  operators.prefix.not = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["!", "\u00ac", "\\[Not]"],
  };
  operators.fake.prefix.bang_bang = {
    precedence: operators.prefix.not.precedence,
    associativity: prec,
    tokens: ["!!"],
  };
  operators.for_all = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2200", "\\[ForAll]"],
  };
  operators.exists = {
    precedence: operators.for_all.precedence,
    associativity: prec,
    tokens: ["\u2203", "\\[Exists]"],
  };
  operators.not_exists = {
    precedence: operators.for_all.precedence,
    associativity: prec,
    tokens: ["\u2204", "\\[NotExists]"],
  };

  const set_relations_prec = next();

  operators.set_relations = {
    element: {
      tokens: ["\\[Element]", "\u2208"],
      precedence: set_relations_prec,
      associativity: prec,
    },
    not_element: {
      tokens: ["\\[NotElement]", "\u2209"],
      precedence: set_relations_prec,
      associativity: prec,
    },
    reverse_element: {
      tokens: ["\\[ReverseElement]", "\u220B"],
      precedence: set_relations_prec,
      associativity: prec,
    },
    not_reverse_element: {
      tokens: ["\\[NotReverseElement]", "\u220C"],
      precedence: set_relations_prec,
      associativity: prec,
    },
  };

  operators.comparison.sameq = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["==="],
  };
  operators.comparison.unsameq = {
    precedence: operators.comparison.sameq.precedence,
    associativity: prec,
    tokens: ["=!="],
  };

  const arrow_prec = next();

  operators.vector_operators = {
    rightvector: {
      tokens: ["\\[RightVector]", "\u21C0"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downrightvector: {
      tokens: ["\\[DownRightVector]", "\u21C1"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftvector: {
      tokens: ["\\[LeftVector]", "\u21BC"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downleftvector: {
      tokens: ["\\[DownLeftVector]", "\u21BD"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightupvector: {
      tokens: ["\\[RightUpVector]", "\u21BE"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftupvector: {
      tokens: ["\\[LeftUpVector]", "\u21BF"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightdownvector: {
      tokens: ["\\[RightDownVector]", "\u21C2"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftdownvector: {
      tokens: ["\\[LeftDownVector]", "\u21C3"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftrightvector: {
      tokens: ["\\[LeftRightVector]", "\u294E"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downleftrightvector: {
      tokens: ["\\[DownLeftRightVector]", "\u2950"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightupdownvector: {
      tokens: ["\\[RightUpDownVector]", "\u294F"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftupdownvector: {
      tokens: ["\\[LeftUpDownVector]", "\u2951"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightvectorbar: {
      tokens: ["\\[RightVectorBar]", "\u2953"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downrightvectorbar: {
      tokens: ["\\[DownRightVectorBar]", "\u2957"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftvectorbar: {
      tokens: ["\\[LeftVectorBar]", "\u2952"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downleftvectorbar: {
      tokens: ["\\[DownLeftVectorBar]", "\u2956"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightupvectorbar: {
      tokens: ["\\[RightUpVectorBar]", "\u2954"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftupvectorbar: {
      tokens: ["\\[LeftUpVectorBar]", "\u2958"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightdownvectorbar: {
      tokens: ["\\[RightDownVectorBar]", "\u2955"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftdownvectorbar: {
      tokens: ["\\[LeftDownVectorBar]", "\u2959"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightteevector: {
      tokens: ["\\[RightTeeVector]", "\u295B"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downrightteevector: {
      tokens: ["\\[DownRightTeeVector]", "\u295F"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftteevector: {
      tokens: ["\\[LeftTeeVector]", "\u295A"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downleftteevector: {
      tokens: ["\\[DownLeftTeeVector]", "\u295E"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightupteevector: {
      tokens: ["\\[RightUpTeeVector]", "\u295C"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftupteevector: {
      tokens: ["\\[LeftUpTeeVector]", "\u2960"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightdownteevector: {
      tokens: ["\\[RightDownTeeVector]", "\u295D"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftdownteevector: {
      tokens: ["\\[LeftDownTeeVector]", "\u2961"],
      precedence: arrow_prec,
      associativity: prec,
    },
    rightarrow: {
      tokens: ["\\[RightArrow]", "\u2192"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftarrow: {
      tokens: ["\\[LeftArrow]", "\u2190"],
      precedence: arrow_prec,
      associativity: prec,
    },
    uparrow: {
      tokens: ["\\[UpArrow]", "\u2191"],
      precedence: arrow_prec,
      associativity: prec,
    },
    downarrow: {
      tokens: ["\\[DownArrow]", "\u2193"],
      precedence: arrow_prec,
      associativity: prec,
    },
    leftrightarrow: {
      tokens: ["\\[LeftRightArrow]", "\u2194"],
      precedence: arrow_prec,
      associativity: prec,
    },
    updownarrow: {
      tokens: ["\\[UpDownArrow]", "\u2195"],
      precedence: arrow_prec,
      associativity: prec,
    },
    shortrightarrow: {
      tokens: ["\\[ShortRightArrow]", "\uF525"],
      precedence: arrow_prec,
      associativity: prec,
    },
    shortleftarrow: {
      tokens: ["\\[ShortLeftArrow]", "\uF526"],
      precedence: arrow_prec,
      associativity: prec,
    },
    shortuparrow: {
      tokens: ["\\[ShortUpArrow]", "\uF52A"],
      precedence: arrow_prec,
      associativity: prec,
    },
    shortdownarrow: {
      tokens: ["\\[ShortDownArrow]", "\uF52B"],
      precedence: arrow_prec,
      associativity: prec,
    },
  };

  operators.vertical_bar = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uf3d0", "\\[VerticalBar]"],
  };
  operators.not_vertical_bar = {
    precedence: operators.vertical_bar.precedence,
    associativity: prec,
    tokens: ["\uf3d1", "\\[NotVerticalBar]"],
  };
  operators.double_vertical_bar = {
    precedence: operators.vertical_bar.precedence,
    associativity: prec,
    tokens: ["\u2225", "\\[DoubleVerticalBar]"],
  };
  operators.not_double_vertical_bar = {
    precedence: operators.vertical_bar.precedence,
    associativity: prec,
    tokens: ["\u2226", "\\[NotDoubleVerticalBar]"],
  };

  const ordering_prec = next();

  operators.comparison.equal = {
    precedence: ordering_prec,
    associativity: prec.left,
    tokens: ["==", "\uf431", "\uf7d9", "\\[Equal]", "\\[LongEqual]"],
  };
  operators.comparison.unequal = {
    precedence: ordering_prec,
    associativity: prec.left,
    tokens: ["!=", "\u2260", "\\[NotEqual]"],
  };
  operators.comparison.greater = {
    precedence: ordering_prec,
    associativity: prec.left,
    tokens: [">"],
  };
  operators.comparison.greater_equal = {
    precedence: ordering_prec,
    associativity: prec.left,
    tokens: [
      ">=",
      "\u2265",
      "\\[GreaterEqual]",
      "\\[GreaterSlantEqual]",
      "\u2AA2",
    ],
  };
  operators.comparison.less = {
    precedence: ordering_prec,
    associativity: prec.left,
    tokens: ["<"],
  };
  operators.comparison.less_equal = {
    precedence: ordering_prec,
    associativity: prec.left,
    tokens: ["<=", "\u2264", "\\[LessEqual]", "\u2A7D", "\\[LessSlantEqual]"],
  };

  operators.other_ordering = {
    Tilde: {
      tokens: ["\\[Tilde]", "\u223C"],
      precedence: 390,
      associativity: prec,
    },
    NotTilde: {
      tokens: ["\\[NotTilde]", "\u2241"],
      precedence: 390,
      associativity: prec,
    },
    EqualTilde: {
      tokens: ["\\[EqualTilde]", "\u2242"],
      precedence: 390,
      associativity: prec,
    },
    TildeEqual: {
      tokens: ["\\[TildeEqual]", "\u2243"],
      precedence: 390,
      associativity: prec,
    },
    NotTildeEqual: {
      tokens: ["\\[NotTildeEqual]", "\u2244"],
      precedence: 390,
      associativity: prec,
    },
    TildeFullEqual: {
      tokens: ["\\[TildeFullEqual]", "\u2245"],
      precedence: 390,
      associativity: prec,
    },
    TildeTilde: {
      tokens: ["\\[TildeTilde]", "\u2248"],
      precedence: 390,
      associativity: prec,
    },
    NotTildeTilde: {
      tokens: ["\\[NotTildeTilde]", "\u2249"],
      precedence: 390,
      associativity: prec,
    },
    NotEqualTilde: {
      tokens: ["\\[NotEqualTilde]", "\uF400"],
      precedence: 390,
      associativity: prec,
    },
    NotTildeFullEqual: {
      tokens: ["\\[NotTildeFullEqual]", "\u2247"],
      precedence: 390,
      associativity: prec,
    },
    LessTilde: {
      tokens: ["\\[LessTilde]", "\u2272"],
      precedence: 390,
      associativity: prec,
    },
    GreaterTilde: {
      tokens: ["\\[GreaterTilde]", "\u2273"],
      precedence: 390,
      associativity: prec,
    },
    NotLessTilde: {
      tokens: ["\\[NotLessTilde]", "\u2274"],
      precedence: 390,
      associativity: prec,
    },
    NotGreaterTilde: {
      tokens: ["\\[NotGreaterTilde]", "\u2275"],
      precedence: 390,
      associativity: prec,
    },
    LeftTriangle: {
      tokens: ["\\[LeftTriangle]", "\u22B2"],
      precedence: 390,
      associativity: prec,
    },
    RightTriangle: {
      tokens: ["\\[RightTriangle]", "\u22B3"],
      precedence: 390,
      associativity: prec,
    },
    LeftTriangleEqual: {
      tokens: ["\\[LeftTriangleEqual]", "\u22B4"],
      precedence: 390,
      associativity: prec,
    },
    RightTriangleEqual: {
      tokens: ["\\[RightTriangleEqual]", "\u22B5"],
      precedence: 390,
      associativity: prec,
    },
    LeftTriangleBar: {
      tokens: ["\\[LeftTriangleBar]", "\u29CF"],
      precedence: 390,
      associativity: prec,
    },
    RightTriangleBar: {
      tokens: ["\\[RightTriangleBar]", "\u29D0"],
      precedence: 390,
      associativity: prec,
    },
    NotLeftTriangleBar: {
      tokens: ["\\[NotLeftTriangleBar]", "\uF412"],
      precedence: 390,
      associativity: prec,
    },
    NotRightTriangleBar: {
      tokens: ["\\[NotRightTriangleBar]", "\uF413"],
      precedence: 390,
      associativity: prec,
    },
    NotLeftTriangle: {
      tokens: ["\\[NotLeftTriangle]", "\u22EA"],
      precedence: 390,
      associativity: prec,
    },
    NotLeftTriangleEqual: {
      tokens: ["\\[NotLeftTriangleEqual]", "\u22EC"],
      precedence: 390,
      associativity: prec,
    },
    NotRightTriangle: {
      tokens: ["\\[NotRightTriangle]", "\u22EB"],
      precedence: 390,
      associativity: prec,
    },
    NotRightTriangleEqual: {
      tokens: ["\\[NotRightTriangleEqual]", "\u22ED"],
      precedence: 390,
      associativity: prec,
    },
    NotEqual: {
      tokens: ["\\[NotEqual]", "\u2260"],
      precedence: 390,
      associativity: prec,
    },
    NotLess: {
      tokens: ["\\[NotLess]", "\u226E"],
      precedence: 390,
      associativity: prec,
    },
    NotGreater: {
      tokens: ["\\[NotGreater]", "\u226F"],
      precedence: 390,
      associativity: prec,
    },
    LessEqual: {
      tokens: ["\\[LessEqual]", "\u2264"],
      precedence: 390,
      associativity: prec,
    },
    LessLess: {
      tokens: ["\\[LessLess]", "\u226A"],
      precedence: 390,
      associativity: prec,
    },
    GreaterGreater: {
      tokens: ["\\[GreaterGreater]", "\u226B"],
      precedence: 390,
      associativity: prec,
    },
    NotLessEqual: {
      tokens: ["\\[NotLessEqual]", "\u2270"],
      precedence: 390,
      associativity: prec,
    },
    GreaterEqual: {
      tokens: ["\\[GreaterEqual]", "\u2265"],
      precedence: 390,
      associativity: prec,
    },
    NotGreaterEqual: {
      tokens: ["\\[NotGreaterEqual]", "\u2271"],
      precedence: 390,
      associativity: prec,
    },
    LessSlantEqual: {
      tokens: ["\\[LessSlantEqual]", "\u2A7D"],
      precedence: 390,
      associativity: prec,
    },
    LessFullEqual: {
      tokens: ["\\[LessFullEqual]", "\u2266"],
      precedence: 390,
      associativity: prec,
    },
    NotLessLess: {
      tokens: ["\\[NotLessLess]", "\uF422"],
      precedence: 390,
      associativity: prec,
    },
    NotNestedLessLess: {
      tokens: ["\\[NotNestedLessLess]", "\uF423"],
      precedence: 390,
      associativity: prec,
    },
    NotLessSlantEqual: {
      tokens: ["\\[NotLessSlantEqual]", "\uF424"],
      precedence: 390,
      associativity: prec,
    },
    NotLessFullEqual: {
      tokens: ["\\[NotLessFullEqual]", "\u2268"],
      precedence: 390,
      associativity: prec,
    },
    NestedLessLess: {
      tokens: ["\\[NestedLessLess]", "\u2AA1"],
      precedence: 390,
      associativity: prec,
    },
    NestedGreaterGreater: {
      tokens: ["\\[NestedGreaterGreater]", "\u2AA2"],
      precedence: 390,
      associativity: prec,
    },
    GreaterSlantEqual: {
      tokens: ["\\[GreaterSlantEqual]", "\u2A7E"],
      precedence: 390,
      associativity: prec,
    },
    GreaterFullEqual: {
      tokens: ["\\[GreaterFullEqual]", "\u2267"],
      precedence: 390,
      associativity: prec,
    },
    NotGreaterGreater: {
      tokens: ["\\[NotGreaterGreater]", "\uF427"],
      precedence: 390,
      associativity: prec,
    },
    NotNestedGreaterGreater: {
      tokens: ["\\[NotNestedGreaterGreater]", "\uF428"],
      precedence: 390,
      associativity: prec,
    },
    NotGreaterSlantEqual: {
      tokens: ["\\[NotGreaterSlantEqual]", "\uF429"],
      precedence: 390,
      associativity: prec,
    },
    NotGreaterFullEqual: {
      tokens: ["\\[NotGreaterFullEqual]", "\u2269"],
      precedence: 390,
      associativity: prec,
    },
    LessGreater: {
      tokens: ["\\[LessGreater]", "\u2276"],
      precedence: 390,
      associativity: prec,
    },
    GreaterLess: {
      tokens: ["\\[GreaterLess]", "\u2277"],
      precedence: 390,
      associativity: prec,
    },
    NotLessGreater: {
      tokens: ["\\[NotLessGreater]", "\u2278"],
      precedence: 390,
      associativity: prec,
    },
    NotGreaterLess: {
      tokens: ["\\[NotGreaterLess]", "\u2279"],
      precedence: 390,
      associativity: prec,
    },
    LessEqualGreater: {
      tokens: ["\\[LessEqualGreater]", "\u22DA"],
      precedence: 390,
      associativity: prec,
    },
    GreaterEqualLess: {
      tokens: ["\\[GreaterEqualLess]", "\u22DB"],
      precedence: 390,
      associativity: prec,
    },
    VectorGreater: {
      tokens: ["\\[VectorGreater]", "\uF434"],
      precedence: 390,
      associativity: prec,
    },
    VectorGreaterEqual: {
      tokens: ["\\[VectorGreaterEqual]", "\uF435"],
      precedence: 390,
      associativity: prec,
    },
    VectorLess: {
      tokens: ["\\[VectorLess]", "\uF436"],
      precedence: 390,
      associativity: prec,
    },
    VectorLessEqual: {
      tokens: ["\\[VectorLessEqual]", "\uF437"],
      precedence: 390,
      associativity: prec,
    },
  };

  operators.directed_edge = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["\\[DirectedEdge]", "\uf3d5"],
  };
  operators.undirected_edge = {
    precedence: operators.directed_edge.precedence,
    associativity: prec,
    tokens: ["\\[UndirectedEdge]", "\uf3d4"],
  };
  operators.span = {
    precedence: next(),
    associativity: prec.left,
    tokens: [";;"],
  };

  const union_prec = next();
  operators.union = {
    precedence: union_prec,
    associativity: prec.left,
    tokens: ["\u22C3", "[Union]"],
  };
  operators.union_plus = {
    precedence: union_prec,
    associativity: prec.left,
    tokens: ["\u228E", "[UnionPlus]"],
  };
  operators.square_union = {
    precedence: union_prec,
    associativity: prec.left,
    tokens: ["\u2294", "[SquareUnion]"],
  };
  operators.other_union_operators = {
    precedence: union_prec,
    associativity: prec.left,
    tokens: null,
  };

  const intersection_prec = next();
  operators.intersection = {
    tokens: ["\\[Intersection]", "\u22C2"],
    precedence: intersection_prec,
    associativity: prec,
  };
  operators.square_intersection = {
    tokens: ["\\[SquareIntersection]", "\u2293"],
    precedence: intersection_prec,
    associativity: prec,
  };

  operators.infix.plus = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["+"],
  };
  operators.infix.minus = {
    precedence: operators.infix.plus.precedence,
    associativity: prec.left,
    tokens: ["-", "\\[Minus]"],
  };
  operators.infix.plus_minus = {
    precedence: operators.infix.plus.precedence,
    associativity: prec,
    tokens: ["\u00b1", "\\[PlusMinus]"],
  };
  operators.infix.minus_plus = {
    precedence: operators.infix.plus.precedence,
    associativity: prec,
    tokens: ["\u2213", "\\[PlusMinus]"],
  };
  operators.implicit_plus = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uF39E"],
  };
  operators.sum = {
    precedence: next(),
    associativity: prec.left,
    tokens: null,
  };

  const integration_prec = next();
  operators.integral = {
    precedence: integration_prec,
    associativity: prec.left,
    tokens: ["\\[Integral]", "\u222B"],
  };
  operators.contour_integral = {
    precedence: integration_prec,
    associativity: prec.left,
    tokens: ["\\[ContourIntegral]", "\u222E"],
  };
  operators.double_contour_integral = {
    precedence: integration_prec,
    associativity: prec.left,
    tokens: ["\\[DoubleContourIntegral]", "\u222F"],
  };
  operators.counter_clockwise_contour_integral = {
    precedence: integration_prec,
    associativity: prec.left,
    tokens: ["\\[CounterClockwiseContourIntegral]", "\u2233"],
  };
  operators.clockwise_contour_integral = {
    precedence: integration_prec,
    associativity: prec.left,
    tokens: ["\\[ClockwiseContourIntegral]", "\u2232"],
  };
  operators.expectation_e = {
    precedence: integration_prec,
    associativity: prec,
    tokens: ["\\[ExpectationE]", "\uF3DD"],
  };
  operators.probability_pr = {
    precedence: integration_prec,
    associativity: prec,
    tokens: ["\\[ProbabilityPr]", "\uF3DC"],
  };

  operators.infix.circle_plus = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2295"],
  };
  operators.infix.circle_minus = {
    precedence: operators.infix.circle_plus.precedence,
    associativity: prec,
    tokens: ["\u2296"],
  };
  operators.infix.cup = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2323"],
  };
  operators.infix.cap = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2322"],
  };
  operators.infix.coproduct = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2210"],
  };
  operators.infix.vertical_tilde = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2240"],
  };
  operators.product = {
    precedence: next(),
    associativity: prec.left,
    tokens: null,
  };
  operators.continued_fraction_k = {
    precedence: operators.product.precedence,
    associativity: prec,
    tokens: ["\uf3d9"],
  };
  operators.infix.star = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u22c6"],
  };
  operators.infix.times = {
    precedence: operators.infix.star.precedence,
    associativity: prec,
    tokens: ["*", "\u00d7"],
  };
  operators.fake.implicit_times = {
    precedence: operators.infix.star.precedence,
    associativity: prec,
    tokens: [
      "\u2062",
      "\uF360",
      "\u0020",
      " ",
      "\\[InvisibleTimes]",
      "\\[InvisibleSpace]",
      "\\[RawSpace]",
    ],
  };
  operators.center_dot = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u00b7", "\\[CenterDot]"],
  };
  operators.infix.circle_times = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2297", "\\[CircleTime]"],
  };
  operators.infix.vee = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u22c1", "\\[Vee]"],
  };
  operators.infix.wedge = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u22c0", "\\[Wedge]"],
  };
  operators.infix.diamond = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u22c4", "\\[Diamond]"],
  };
  operators.infix.backslash = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["\u2216", "\\[Backslash"],
  };
  operators.infix.divide = {
    precedence: next(),
    associativity: prec,
    tokens: ["/", "\u00f7"],
  };
  operators.divides = {
    precedence: operators.infix.divide.precedence,
    associativity: prec,
    tokens: ["\u2223", "\\[Divides]"],
  };
  operators.division_slash = {
    precedence: operators.infix.divide.precedence,
    associativity: prec,
    tokens: ["\u2215", "\\[DivisionSlash]"],
  };
  operators.prefix.minus = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["-", "\\[Minus]"],
  };
  operators.prefix.plus = {
    precedence: operators.prefix.minus.precedence,
    associativity: prec,
    tokens: ["+"],
  };
  operators.prefix.plus_minus = {
    precedence: operators.prefix.minus.precedence,
    associativity: prec,
    tokens: ["\u00b1"],
  };
  operators.prefix.minus_plus = {
    precedence: operators.prefix.minus.precedence,
    associativity: prec,
    tokens: ["\u2213"],
  };
  operators.prefix.circle_times = {
    precedence: operators.prefix.minus.precedence,
    associativity: prec,
    tokens: ["\u2297"],
  };
  operators.prefix.coproduct = {
    precedence: operators.prefix.minus.precedence,
    associativity: prec,
    tokens: ["\u2210"],
  };
  operators.infix.dot = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["."],
  };
  operators.divergence = {
    precedence: operators.infix.dot.precedence,
    associativity: prec.left,
    tokens: ["\uF3D7", "\\[Divergence]"],
  };
  operators.curl = {
    precedence: operators.infix.dot.precedence,
    associativity: prec.left,
    tokens: ["\uF3D8", "\\[Curl]"],
  };
  operators.tensor_product = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uF3DA", "\\[TensorProduct]"],
  };
  operators.infix.cross = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uf4a0"],
  };
  operators.tensor_wedge = {
    precedence: operators.infix.cross.precedence,
    associativity: prec,
    tokens: ["\uF3DB", "\\[TensorWedge]"],
  };
  operators.infix.non_commutative_multiply = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["**"],
  };
  operators.infix.circle_dot = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2299"],
  };
  operators.permutation_product = {
    precedence: operators.infix.circle_dot.precedence,
    associativity: prec,
    tokens: ["\uF3DE", "\\[PermutationProduct]"],
  };
  operators.infix.small_circle = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2218", "\\[SmallCircle]"],
  };
  operators.square = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uf520", "\\[Square]"],
  };
  operators.prefix.del = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2207", "\\[Del]"],
  };
  operators.laplacian = {
    precedence: operators.prefix.del.precedence,
    associativity: prec.left,
    tokens: ["\u2206", "\\[Laplacian]"],
  };
  operators.discrete_shift = {
    precedence: operators.prefix.del.precedence,
    associativity: prec,
    tokens: ["\\[DiscreteShift]", "\uF4A3"],
  };
  operators.difference_delta = {
    precedence: operators.prefix.del.precedence,
    associativity: prec,
    tokens: ["\\[DifferenceDelta]", "\uF4A4"],
  };
  operators.discrete_ratio = {
    precedence: operators.prefix.del.precedence,
    associativity: prec,
    tokens: ["\\[DiscreteRatio]", "\uF4A5"],
  };
  operators.partial_d = {
    precedence: operators.prefix.del.precedence,
    associativity: prec,
    tokens: ["\\[PartialD]", "\u2202"],
  };

  operators.piecewise = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uf361", "\\[Piecewise]"],
  };
  operators.prefix.differential_d = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uF74C", "\\[DifferentialD]"],
  };
  operators.capital_differential_d = {
    precedence: operators.prefix.differential_d.precedence,
    associativity: prec,
    tokens: ["\uF74B", "\\[CapitalDifferentialD]"],
  };
  operators.prefix.sqrt = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u221a", "\\[Sqrt]"],
  };
  operators.cube_root = {
    precedence: operators.prefix.sqrt.precedence,
    associativity: prec,
    tokens: ["\u221B", "\\[CubeRoot]"],
  };
  operators.infix.power = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["^"],
  };
  operators.string_join = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["<>"],
  };
  operators.postfix.derivative = {
    precedence: next(),
    associativity: prec.left,
    tokens: [repeat1("'")],
  };
  operators.postfix.transpose = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\uf3c7", "\\[Transpose]"],
  };
  operators.postfix.conjugate = {
    precedence: operators.postfix.transpose.precedence,
    associativity: prec,
    tokens: ["\uf3c8", "\\[Conjugate]"],
  };
  operators.postfix.conjugate_transpose = {
    precedence: operators.postfix.transpose.precedence,
    associativity: prec,
    tokens: ["\uF3C9", "\\[ConjugateTranspose]"],
  };
  operators.postfix.hermitian_conjugate = {
    precedence: operators.postfix.transpose.precedence,
    associativity: prec,
    tokens: ["\uF3CE", "\\[HermitianConjugate]"],
  };
  operators.postfix.factorial = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["!"],
  };
  operators.postfix.double_factorial = {
    precedence: operators.postfix.factorial.precedence,
    associativity: prec,
    tokens: ["!!"],
  };
  operators.infix.apply = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["@@"],
  };
  operators.infix.map = {
    precedence: operators.infix.apply.precedence,
    associativity: prec.right,
    tokens: ["/@"],
  };
  operators.apply_level_one = {
    precedence: operators.infix.apply.precedence,
    associativity: prec.right,
    tokens: ["@@@"],
  };
  operators.map_all = {
    precedence: operators.infix.apply.precedence,
    associativity: prec.right,
    tokens: ["//@"],
  };
  operators.tilde = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["~", "\u223c"],
  };
  operators.infix.prefix_apply = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["@"],
  };
  operators.invisible_application = {
    precedence: operators.infix.prefix_apply.precedence,
    associativity: prec,
    tokens: ["\uf76D", "\\[InvisibleApplication]"],
  };
  operators.infix.application = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u2216", "\\[Application]"],
  };
  operators.infix.right_composition = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["/*"],
  };
  operators.infix.composition = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["@*"],
  };
  operators.prefix.increment = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["++"],
  };
  operators.prefix.decrement = {
    precedence: operators.prefix.increment.precedence,
    associativity: prec,
    tokens: ["--"],
  };
  operators.postfix.increment = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["++"],
  };
  operators.postfix.decrement = {
    precedence: operators.postfix.increment.precedence,
    associativity: prec,
    tokens: ["--"],
  };
  operators.call = {
    precedence: next(),
    associativity: prec.left,
    delimiters: [new Delimiters("[", "]")],
  };
  operators.part = {
    precedence: operators.call.precedence,
    associativity: prec.left,
    delimiters: [
      new Delimiters(seq("[", "["), seq("]", "]")),
      new Delimiters("\u301A", "\u301B"),
      new Delimiters("\\[LeftDoubleBracket]", "\\[RightDoubleBracket]"),
    ],
  };
  operators.pattern.test = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["?"],
  };
  operators.linear_syntax.under = {
    precedence: next(),
    associativity: prec.right,
    tokens: ["\\_"],
  };
  operators.linear_syntax.bang = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\\!"],
  };
  operators.linear_syntax.amp = {
    precedence: operators.linear_syntax.bang,
    associativity: prec.right,
    tokens: ["\\&"],
  };
  operators.linear_syntax.plus = {
    precedence: operators.linear_syntax.bang,
    associativity: prec.right,
    tokens: ["\\+"],
  };
  operators.linear_syntax.percent = {
    precedence: operators.linear_syntax.bang,
    associativity: prec.right,
    tokens: ["\\%"],
  };
  operators.prefix.get = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["\u226a"],
  };
  operators.blank = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["_"],
  };
  operators.out = {
    precedence: next(),
    associativity: prec,
    tokens: ["%"],
  };
  operators.slot = {
    precedence: next(),
    associativity: prec,
    tokens: ["#"],
  };
  operators.message_name = {
    precedence: next(),
    associativity: prec.left,
    tokens: ["::"],
  };
  operators.bracketed.list = {
    precedence: next(),
    associativity: prec.right,
    delimiters: [new Delimiters("{", "}")],
  };
  operators.invisible_prefix_script_base = {
    precedence: next(),
    associativity: prec.left,
    tokens: null,
  };
  operators.invisible_postfix_script_base = {
    precedence: operators.invisible_prefix_script_base.precedence,
    associativity: prec,
    tokens: null,
  };
  operators.highest = {
    precedence: next(),
    associativity: prec.left,
  };
  operators.symbol = {
    precedence: operators.highest.precedence,
    associativity: prec,
  };
  operators.number = {
    precedence: operators.highest.precedence,
    associativity: prec,
  };
  operators.string = {
    precedence: operators.highest.precedence,
    associativity: prec,
  };
  operators.under = {
    precedence: operators.highest.precedence,
    associativity: prec,
    tokens: null,
  };
  operators.assert_false = {
    precedence: next(),
    associativity: prec.left,
    tokens: null,
  };

  return operators;
}

module.exports = {
  ...make_precedences(),
};
