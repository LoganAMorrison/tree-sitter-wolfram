#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 38
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 36
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 3

enum {
  sym_identifier = 1,
  anon_sym_LF = 2,
  anon_sym_SEMI = 3,
  aux_sym_number_token1 = 4,
  aux_sym_number_token2 = 5,
  aux_sym_number_token3 = 6,
  anon_sym_BQUOTE_BQUOTE = 7,
  anon_sym_BQUOTE = 8,
  anon_sym_STAR_CARET = 9,
  anon_sym_PLUS = 10,
  anon_sym_DASH = 11,
  anon_sym_True = 12,
  anon_sym_False = 13,
  anon_sym_Null = 14,
  anon_sym_I = 15,
  anon_sym_ImaginaryI = 16,
  anon_sym_ImaginaryJ = 17,
  anon_sym_ExponentialE = 18,
  anon_sym_Pi = 19,
  anon_sym_BSLASH_LBRACKPi_RBRACK = 20,
  anon_sym_LPAREN_STAR = 21,
  aux_sym_comment_token1 = 22,
  aux_sym_comment_token2 = 23,
  anon_sym_STAR_RPAREN = 24,
  sym_source_file = 25,
  sym_expression = 26,
  sym_atomic = 27,
  sym_number = 28,
  sym_builtin_symbol = 29,
  sym_scoped_symbol = 30,
  sym__symbol = 31,
  sym_comment = 32,
  aux_sym_source_file_repeat1 = 33,
  aux_sym_scoped_symbol_repeat1 = 34,
  aux_sym_comment_repeat1 = 35,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LF] = "\n",
  [anon_sym_SEMI] = ";",
  [aux_sym_number_token1] = "number_token1",
  [aux_sym_number_token2] = "number_token2",
  [aux_sym_number_token3] = "number_token3",
  [anon_sym_BQUOTE_BQUOTE] = "``",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_STAR_CARET] = "*^",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_True] = "True",
  [anon_sym_False] = "False",
  [anon_sym_Null] = "Null",
  [anon_sym_I] = "I",
  [anon_sym_ImaginaryI] = "ImaginaryI",
  [anon_sym_ImaginaryJ] = "ImaginaryJ",
  [anon_sym_ExponentialE] = "ExponentialE",
  [anon_sym_Pi] = "Pi",
  [anon_sym_BSLASH_LBRACKPi_RBRACK] = "\\[Pi]",
  [anon_sym_LPAREN_STAR] = "(*",
  [aux_sym_comment_token1] = "comment_token1",
  [aux_sym_comment_token2] = "comment_token2",
  [anon_sym_STAR_RPAREN] = "*)",
  [sym_source_file] = "source_file",
  [sym_expression] = "expression",
  [sym_atomic] = "atomic",
  [sym_number] = "number",
  [sym_builtin_symbol] = "builtin_symbol",
  [sym_scoped_symbol] = "scoped_symbol",
  [sym__symbol] = "_symbol",
  [sym_comment] = "comment",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_scoped_symbol_repeat1] = "scoped_symbol_repeat1",
  [aux_sym_comment_repeat1] = "comment_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [aux_sym_number_token1] = aux_sym_number_token1,
  [aux_sym_number_token2] = aux_sym_number_token2,
  [aux_sym_number_token3] = aux_sym_number_token3,
  [anon_sym_BQUOTE_BQUOTE] = anon_sym_BQUOTE_BQUOTE,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_STAR_CARET] = anon_sym_STAR_CARET,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_True] = anon_sym_True,
  [anon_sym_False] = anon_sym_False,
  [anon_sym_Null] = anon_sym_Null,
  [anon_sym_I] = anon_sym_I,
  [anon_sym_ImaginaryI] = anon_sym_ImaginaryI,
  [anon_sym_ImaginaryJ] = anon_sym_ImaginaryJ,
  [anon_sym_ExponentialE] = anon_sym_ExponentialE,
  [anon_sym_Pi] = anon_sym_Pi,
  [anon_sym_BSLASH_LBRACKPi_RBRACK] = anon_sym_BSLASH_LBRACKPi_RBRACK,
  [anon_sym_LPAREN_STAR] = anon_sym_LPAREN_STAR,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [aux_sym_comment_token2] = aux_sym_comment_token2,
  [anon_sym_STAR_RPAREN] = anon_sym_STAR_RPAREN,
  [sym_source_file] = sym_source_file,
  [sym_expression] = sym_expression,
  [sym_atomic] = sym_atomic,
  [sym_number] = sym_number,
  [sym_builtin_symbol] = sym_builtin_symbol,
  [sym_scoped_symbol] = sym_scoped_symbol,
  [sym__symbol] = sym__symbol,
  [sym_comment] = sym_comment,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_scoped_symbol_repeat1] = aux_sym_scoped_symbol_repeat1,
  [aux_sym_comment_repeat1] = aux_sym_comment_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_number_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_number_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_number_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_True] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_False] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_I] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ImaginaryI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ImaginaryJ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ExponentialE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Pi] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_LBRACKPi_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN_STAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_STAR_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_atomic] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_builtin_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym_scoped_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym__symbol] = {
    .visible = false,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_scoped_symbol_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_context = 1,
  field_name = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_context] = "context",
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_context, 0},
    {field_name, 1},
  [2] =
    {field_context, 0},
    {field_context, 1},
    {field_name, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static inline bool sym_identifier_character_set_1(int32_t c) {
  return (c < 6656
    ? (c < 2979
      ? (c < 2308
        ? (c < 1376
          ? (c < 880
            ? (c < 192
              ? (c < 170
                ? (c < 'A'
                  ? c == '$'
                  : (c <= 'Z' || (c >= 'a' && c <= 'z')))
                : (c <= 170 || (c < 186
                  ? c == 181
                  : c <= 186)))
              : (c <= 214 || (c < 736
                ? (c < 248
                  ? (c >= 216 && c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))
                : (c <= 740 || (c < 750
                  ? c == 748
                  : c <= 750)))))
            : (c <= 884 || (c < 910
              ? (c < 902
                ? (c < 890
                  ? (c >= 886 && c <= 887)
                  : (c <= 893 || c == 895))
                : (c <= 902 || (c < 908
                  ? (c >= 904 && c <= 906)
                  : c <= 908)))
              : (c <= 929 || (c < 1162
                ? (c < 1015
                  ? (c >= 931 && c <= 1013)
                  : c <= 1153)
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1765
              ? (c < 1646
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1808
                ? (c < 1786
                  ? (c >= 1774 && c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1994 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2160
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : c <= 2154)
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2417
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : c <= 2448)))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2544 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2649
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : c <= 2617)
                : (c <= 2652 || (c < 2674
                  ? c == 2654
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2866
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2831
                ? (c < 2809
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2949
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2969
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 4159
        ? (c < 3412
          ? (c < 3214
            ? (c < 3114
              ? (c < 3077
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : c <= 3112)))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3313
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3314 || (c < 3346
                ? (c < 3342
                  ? (c >= 3332 && c <= 3340)
                  : c <= 3344)
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3724
            ? (c < 3520
              ? (c < 3482
                ? (c < 3450
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))
                : (c <= 3505 || (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : c <= 3517)))
              : (c <= 3526 || (c < 3713
                ? (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : (c <= 3635 || (c >= 3648 && c <= 3654)))
                : (c <= 3714 || (c < 3718
                  ? c == 3716
                  : c <= 3722)))))
            : (c <= 3747 || (c < 3804
              ? (c < 3773
                ? (c < 3751
                  ? c == 3749
                  : (c <= 3760 || (c >= 3762 && c <= 3763)))
                : (c <= 3773 || (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : c <= 3782)))
              : (c <= 3807 || (c < 3913
                ? (c < 3904
                  ? c == 3840
                  : c <= 3911)
                : (c <= 3948 || (c < 4096
                  ? (c >= 3976 && c <= 3980)
                  : c <= 4138)))))))))
        : (c <= 4159 || (c < 4888
          ? (c < 4688
            ? (c < 4238
              ? (c < 4197
                ? (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : (c <= 4189 || c == 4193))
                : (c <= 4198 || (c < 4213
                  ? (c >= 4206 && c <= 4208)
                  : c <= 4225)))
              : (c <= 4238 || (c < 4304
                ? (c < 4295
                  ? (c >= 4256 && c <= 4293)
                  : (c <= 4295 || c == 4301))
                : (c <= 4346 || (c < 4682
                  ? (c >= 4348 && c <= 4680)
                  : c <= 4685)))))
            : (c <= 4694 || (c < 4792
              ? (c < 4746
                ? (c < 4698
                  ? c == 4696
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))
                : (c <= 4749 || (c < 4786
                  ? (c >= 4752 && c <= 4784)
                  : c <= 4789)))
              : (c <= 4798 || (c < 4808
                ? (c < 4802
                  ? c == 4800
                  : c <= 4805)
                : (c <= 4822 || (c < 4882
                  ? (c >= 4824 && c <= 4880)
                  : c <= 4885)))))))
          : (c <= 4954 || (c < 6016
            ? (c < 5792
              ? (c < 5121
                ? (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : (c <= 5109 || (c >= 5112 && c <= 5117)))
                : (c <= 5740 || (c < 5761
                  ? (c >= 5743 && c <= 5759)
                  : c <= 5786)))
              : (c <= 5866 || (c < 5952
                ? (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))
                : (c <= 5969 || (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : c <= 6000)))))
            : (c <= 6067 || (c < 6320
              ? (c < 6272
                ? (c < 6108
                  ? c == 6103
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))
              : (c <= 6389 || (c < 6512
                ? (c < 6480
                  ? (c >= 6400 && c <= 6430)
                  : c <= 6509)
                : (c <= 6516 || (c < 6576
                  ? (c >= 6528 && c <= 6571)
                  : c <= 6601)))))))))))))
    : (c <= 6678 || (c < 43259
      ? (c < 8579
        ? (c < 8031
          ? (c < 7401
            ? (c < 7098
              ? (c < 6981
                ? (c < 6823
                  ? (c >= 6688 && c <= 6740)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7086
                  ? (c >= 7043 && c <= 7072)
                  : c <= 7087)))
              : (c <= 7141 || (c < 7296
                ? (c < 7245
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 7968
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))
              : (c <= 8005 || (c < 8025
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : c <= 8023)
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))))))
          : (c <= 8061 || (c < 8450
            ? (c < 8150
              ? (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))
              : (c <= 8155 || (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))))
            : (c <= 8450 || (c < 8488
              ? (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))
              : (c <= 8488 || (c < 8508
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : c <= 8505)
                : (c <= 8511 || (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : c <= 8526)))))))))
        : (c <= 8580 || (c < 12593
          ? (c < 11712
            ? (c < 11568
              ? (c < 11520
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : c <= 11565)))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12347
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12337
                  ? (c >= 12293 && c <= 12294)
                  : c <= 12341)))
              : (c <= 12348 || (c < 12449
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)
                : (c <= 12538 || (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : c <= 12591)))))))
          : (c <= 12686 || (c < 42775
            ? (c < 42192
              ? (c < 19903
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || c == 13312))
                : (c <= 19903 || (c < 40959
                  ? c == 19968
                  : c <= 42124)))
              : (c <= 42237 || (c < 42560
                ? (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : c <= 42725)))))
            : (c <= 42783 || (c < 43011
              ? (c < 42963
                ? (c < 42891
                  ? (c >= 42786 && c <= 42888)
                  : (c <= 42954 || (c >= 42960 && c <= 42961)))
                : (c <= 42963 || (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : c <= 43009)))
              : (c <= 43013 || (c < 43072
                ? (c < 43020
                  ? (c >= 43015 && c <= 43018)
                  : c <= 43042)
                : (c <= 43123 || (c < 43250
                  ? (c >= 43138 && c <= 43187)
                  : c <= 43255)))))))))))
      : (c <= 43259 || (c < 65313
        ? (c < 43808
          ? (c < 43642
            ? (c < 43488
              ? (c < 43360
                ? (c < 43274
                  ? (c >= 43261 && c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43471
                  ? (c >= 43396 && c <= 43442)
                  : c <= 43471)))
              : (c <= 43492 || (c < 43584
                ? (c < 43514
                  ? (c >= 43494 && c <= 43503)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43616
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43638)))))
            : (c <= 43642 || (c < 43739
              ? (c < 43705
                ? (c < 43697
                  ? (c >= 43646 && c <= 43695)
                  : (c <= 43697 || (c >= 43701 && c <= 43702)))
                : (c <= 43709 || (c < 43714
                  ? c == 43712
                  : c <= 43714)))
              : (c <= 43741 || (c < 43777
                ? (c < 43762
                  ? (c >= 43744 && c <= 43754)
                  : c <= 43764)
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55203
                  ? c == 44032
                  : c <= 55203)))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64467
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : c <= 64433)))
              : (c <= 64829 || (c < 65008
                ? (c < 64914
                  ? (c >= 64848 && c <= 64911)
                  : c <= 64967)
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65338 || (c < 66864
          ? (c < 66176
            ? (c < 65536
              ? (c < 65482
                ? (c < 65382
                  ? (c >= 65345 && c <= 65370)
                  : (c <= 65470 || (c >= 65474 && c <= 65479)))
                : (c <= 65487 || (c < 65498
                  ? (c >= 65490 && c <= 65495)
                  : c <= 65500)))
              : (c <= 65547 || (c < 65599
                ? (c < 65576
                  ? (c >= 65549 && c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))
                : (c <= 65613 || (c < 65664
                  ? (c >= 65616 && c <= 65629)
                  : c <= 65786)))))
            : (c <= 66204 || (c < 66464
              ? (c < 66370
                ? (c < 66304
                  ? (c >= 66208 && c <= 66256)
                  : (c <= 66335 || (c >= 66349 && c <= 66368)))
                : (c <= 66377 || (c < 66432
                  ? (c >= 66384 && c <= 66421)
                  : c <= 66461)))
              : (c <= 66499 || (c < 66736
                ? (c < 66560
                  ? (c >= 66504 && c <= 66511)
                  : c <= 66717)
                : (c <= 66771 || (c < 66816
                  ? (c >= 66776 && c <= 66811)
                  : c <= 66855)))))))
          : (c <= 66915 || (c < 67506
            ? (c < 66995
              ? (c < 66964
                ? (c < 66940
                  ? (c >= 66928 && c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))
                : (c <= 66965 || (c < 66979
                  ? (c >= 66967 && c <= 66977)
                  : c <= 66993)))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67680
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67808
                  ? (c >= 67712 && c <= 67742)
                  : c <= 67826)
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static inline bool sym_identifier_character_set_2(int32_t c) {
  return (c < 6656
    ? (c < 2979
      ? (c < 2308
        ? (c < 1376
          ? (c < 750
            ? (c < 186
              ? (c < 'a'
                ? (c < '0'
                  ? c == '$'
                  : (c <= '9' || (c >= 'A' && c <= 'Z')))
                : (c <= 'z' || (c < 181
                  ? c == 170
                  : c <= 181)))
              : (c <= 186 || (c < 710
                ? (c < 216
                  ? (c >= 192 && c <= 214)
                  : (c <= 246 || (c >= 248 && c <= 705)))
                : (c <= 721 || (c < 748
                  ? (c >= 736 && c <= 740)
                  : c <= 748)))))
            : (c <= 750 || (c < 908
              ? (c < 895
                ? (c < 886
                  ? (c >= 880 && c <= 884)
                  : (c <= 887 || (c >= 890 && c <= 893)))
                : (c <= 895 || (c < 904
                  ? c == 902
                  : c <= 906)))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1969
            ? (c < 1765
              ? (c < 1646
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1647 || (c < 1749
                  ? (c >= 1649 && c <= 1747)
                  : c <= 1749)))
              : (c <= 1766 || (c < 1808
                ? (c < 1786
                  ? (c >= 1774 && c <= 1775)
                  : (c <= 1788 || c == 1791))
                : (c <= 1808 || (c < 1869
                  ? (c >= 1810 && c <= 1839)
                  : c <= 1957)))))
            : (c <= 1969 || (c < 2088
              ? (c < 2048
                ? (c < 2036
                  ? (c >= 1994 && c <= 2026)
                  : (c <= 2037 || c == 2042))
                : (c <= 2069 || (c < 2084
                  ? c == 2074
                  : c <= 2084)))
              : (c <= 2088 || (c < 2160
                ? (c < 2144
                  ? (c >= 2112 && c <= 2136)
                  : c <= 2154)
                : (c <= 2183 || (c < 2208
                  ? (c >= 2185 && c <= 2190)
                  : c <= 2249)))))))))
        : (c <= 2361 || (c < 2693
          ? (c < 2527
            ? (c < 2451
              ? (c < 2417
                ? (c < 2384
                  ? c == 2365
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2447
                  ? (c >= 2437 && c <= 2444)
                  : c <= 2448)))
              : (c <= 2472 || (c < 2493
                ? (c < 2482
                  ? (c >= 2474 && c <= 2480)
                  : (c <= 2482 || (c >= 2486 && c <= 2489)))
                : (c <= 2493 || (c < 2524
                  ? c == 2510
                  : c <= 2525)))))
            : (c <= 2529 || (c < 2610
              ? (c < 2575
                ? (c < 2556
                  ? (c >= 2544 && c <= 2545)
                  : (c <= 2556 || (c >= 2565 && c <= 2570)))
                : (c <= 2576 || (c < 2602
                  ? (c >= 2579 && c <= 2600)
                  : c <= 2608)))
              : (c <= 2611 || (c < 2649
                ? (c < 2616
                  ? (c >= 2613 && c <= 2614)
                  : c <= 2617)
                : (c <= 2652 || (c < 2674
                  ? c == 2654
                  : c <= 2676)))))))
          : (c <= 2701 || (c < 2866
            ? (c < 2768
              ? (c < 2738
                ? (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : (c <= 2728 || (c >= 2730 && c <= 2736)))
                : (c <= 2739 || (c < 2749
                  ? (c >= 2741 && c <= 2745)
                  : c <= 2749)))
              : (c <= 2768 || (c < 2831
                ? (c < 2809
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2809 || (c >= 2821 && c <= 2828)))
                : (c <= 2832 || (c < 2858
                  ? (c >= 2835 && c <= 2856)
                  : c <= 2864)))))
            : (c <= 2867 || (c < 2949
              ? (c < 2911
                ? (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2947
                  ? c == 2929
                  : c <= 2947)))
              : (c <= 2954 || (c < 2969
                ? (c < 2962
                  ? (c >= 2958 && c <= 2960)
                  : c <= 2965)
                : (c <= 2970 || (c < 2974
                  ? c == 2972
                  : c <= 2975)))))))))))
      : (c <= 2980 || (c < 4159
        ? (c < 3412
          ? (c < 3214
            ? (c < 3114
              ? (c < 3077
                ? (c < 2990
                  ? (c >= 2984 && c <= 2986)
                  : (c <= 3001 || c == 3024))
                : (c <= 3084 || (c < 3090
                  ? (c >= 3086 && c <= 3088)
                  : c <= 3112)))
              : (c <= 3129 || (c < 3168
                ? (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3205
                  ? c == 3200
                  : c <= 3212)))))
            : (c <= 3216 || (c < 3313
              ? (c < 3261
                ? (c < 3242
                  ? (c >= 3218 && c <= 3240)
                  : (c <= 3251 || (c >= 3253 && c <= 3257)))
                : (c <= 3261 || (c < 3296
                  ? (c >= 3293 && c <= 3294)
                  : c <= 3297)))
              : (c <= 3314 || (c < 3346
                ? (c < 3342
                  ? (c >= 3332 && c <= 3340)
                  : c <= 3344)
                : (c <= 3386 || (c < 3406
                  ? c == 3389
                  : c <= 3406)))))))
          : (c <= 3414 || (c < 3724
            ? (c < 3520
              ? (c < 3482
                ? (c < 3450
                  ? (c >= 3423 && c <= 3425)
                  : (c <= 3455 || (c >= 3461 && c <= 3478)))
                : (c <= 3505 || (c < 3517
                  ? (c >= 3507 && c <= 3515)
                  : c <= 3517)))
              : (c <= 3526 || (c < 3713
                ? (c < 3634
                  ? (c >= 3585 && c <= 3632)
                  : (c <= 3635 || (c >= 3648 && c <= 3654)))
                : (c <= 3714 || (c < 3718
                  ? c == 3716
                  : c <= 3722)))))
            : (c <= 3747 || (c < 3804
              ? (c < 3773
                ? (c < 3751
                  ? c == 3749
                  : (c <= 3760 || (c >= 3762 && c <= 3763)))
                : (c <= 3773 || (c < 3782
                  ? (c >= 3776 && c <= 3780)
                  : c <= 3782)))
              : (c <= 3807 || (c < 3913
                ? (c < 3904
                  ? c == 3840
                  : c <= 3911)
                : (c <= 3948 || (c < 4096
                  ? (c >= 3976 && c <= 3980)
                  : c <= 4138)))))))))
        : (c <= 4159 || (c < 4888
          ? (c < 4688
            ? (c < 4238
              ? (c < 4197
                ? (c < 4186
                  ? (c >= 4176 && c <= 4181)
                  : (c <= 4189 || c == 4193))
                : (c <= 4198 || (c < 4213
                  ? (c >= 4206 && c <= 4208)
                  : c <= 4225)))
              : (c <= 4238 || (c < 4304
                ? (c < 4295
                  ? (c >= 4256 && c <= 4293)
                  : (c <= 4295 || c == 4301))
                : (c <= 4346 || (c < 4682
                  ? (c >= 4348 && c <= 4680)
                  : c <= 4685)))))
            : (c <= 4694 || (c < 4792
              ? (c < 4746
                ? (c < 4698
                  ? c == 4696
                  : (c <= 4701 || (c >= 4704 && c <= 4744)))
                : (c <= 4749 || (c < 4786
                  ? (c >= 4752 && c <= 4784)
                  : c <= 4789)))
              : (c <= 4798 || (c < 4808
                ? (c < 4802
                  ? c == 4800
                  : c <= 4805)
                : (c <= 4822 || (c < 4882
                  ? (c >= 4824 && c <= 4880)
                  : c <= 4885)))))))
          : (c <= 4954 || (c < 6016
            ? (c < 5792
              ? (c < 5121
                ? (c < 5024
                  ? (c >= 4992 && c <= 5007)
                  : (c <= 5109 || (c >= 5112 && c <= 5117)))
                : (c <= 5740 || (c < 5761
                  ? (c >= 5743 && c <= 5759)
                  : c <= 5786)))
              : (c <= 5866 || (c < 5952
                ? (c < 5888
                  ? (c >= 5873 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))
                : (c <= 5969 || (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : c <= 6000)))))
            : (c <= 6067 || (c < 6320
              ? (c < 6272
                ? (c < 6108
                  ? c == 6103
                  : (c <= 6108 || (c >= 6176 && c <= 6264)))
                : (c <= 6276 || (c < 6314
                  ? (c >= 6279 && c <= 6312)
                  : c <= 6314)))
              : (c <= 6389 || (c < 6512
                ? (c < 6480
                  ? (c >= 6400 && c <= 6430)
                  : c <= 6509)
                : (c <= 6516 || (c < 6576
                  ? (c >= 6528 && c <= 6571)
                  : c <= 6601)))))))))))))
    : (c <= 6678 || (c < 43259
      ? (c < 8579
        ? (c < 8031
          ? (c < 7401
            ? (c < 7098
              ? (c < 6981
                ? (c < 6823
                  ? (c >= 6688 && c <= 6740)
                  : (c <= 6823 || (c >= 6917 && c <= 6963)))
                : (c <= 6988 || (c < 7086
                  ? (c >= 7043 && c <= 7072)
                  : c <= 7087)))
              : (c <= 7141 || (c < 7296
                ? (c < 7245
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7247 || (c >= 7258 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 7968
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : c <= 7965)))
              : (c <= 8005 || (c < 8025
                ? (c < 8016
                  ? (c >= 8008 && c <= 8013)
                  : c <= 8023)
                : (c <= 8025 || (c < 8029
                  ? c == 8027
                  : c <= 8029)))))))
          : (c <= 8061 || (c < 8450
            ? (c < 8150
              ? (c < 8130
                ? (c < 8118
                  ? (c >= 8064 && c <= 8116)
                  : (c <= 8124 || c == 8126))
                : (c <= 8132 || (c < 8144
                  ? (c >= 8134 && c <= 8140)
                  : c <= 8147)))
              : (c <= 8155 || (c < 8305
                ? (c < 8178
                  ? (c >= 8160 && c <= 8172)
                  : (c <= 8180 || (c >= 8182 && c <= 8188)))
                : (c <= 8305 || (c < 8336
                  ? c == 8319
                  : c <= 8348)))))
            : (c <= 8450 || (c < 8488
              ? (c < 8473
                ? (c < 8458
                  ? c == 8455
                  : (c <= 8467 || c == 8469))
                : (c <= 8477 || (c < 8486
                  ? c == 8484
                  : c <= 8486)))
              : (c <= 8488 || (c < 8508
                ? (c < 8495
                  ? (c >= 8490 && c <= 8493)
                  : c <= 8505)
                : (c <= 8511 || (c < 8526
                  ? (c >= 8517 && c <= 8521)
                  : c <= 8526)))))))))
        : (c <= 8580 || (c < 12593
          ? (c < 11712
            ? (c < 11568
              ? (c < 11520
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11557 || (c < 11565
                  ? c == 11559
                  : c <= 11565)))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12347
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12337
                  ? (c >= 12293 && c <= 12294)
                  : c <= 12341)))
              : (c <= 12348 || (c < 12449
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : c <= 12447)
                : (c <= 12538 || (c < 12549
                  ? (c >= 12540 && c <= 12543)
                  : c <= 12591)))))))
          : (c <= 12686 || (c < 42775
            ? (c < 42192
              ? (c < 19903
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || c == 13312))
                : (c <= 19903 || (c < 40959
                  ? c == 19968
                  : c <= 42124)))
              : (c <= 42237 || (c < 42560
                ? (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : c <= 42725)))))
            : (c <= 42783 || (c < 43011
              ? (c < 42963
                ? (c < 42891
                  ? (c >= 42786 && c <= 42888)
                  : (c <= 42954 || (c >= 42960 && c <= 42961)))
                : (c <= 42963 || (c < 42994
                  ? (c >= 42965 && c <= 42969)
                  : c <= 43009)))
              : (c <= 43013 || (c < 43072
                ? (c < 43020
                  ? (c >= 43015 && c <= 43018)
                  : c <= 43042)
                : (c <= 43123 || (c < 43250
                  ? (c >= 43138 && c <= 43187)
                  : c <= 43255)))))))))))
      : (c <= 43259 || (c < 65313
        ? (c < 43808
          ? (c < 43642
            ? (c < 43488
              ? (c < 43360
                ? (c < 43274
                  ? (c >= 43261 && c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43471
                  ? (c >= 43396 && c <= 43442)
                  : c <= 43471)))
              : (c <= 43492 || (c < 43584
                ? (c < 43514
                  ? (c >= 43494 && c <= 43503)
                  : (c <= 43518 || (c >= 43520 && c <= 43560)))
                : (c <= 43586 || (c < 43616
                  ? (c >= 43588 && c <= 43595)
                  : c <= 43638)))))
            : (c <= 43642 || (c < 43739
              ? (c < 43705
                ? (c < 43697
                  ? (c >= 43646 && c <= 43695)
                  : (c <= 43697 || (c >= 43701 && c <= 43702)))
                : (c <= 43709 || (c < 43714
                  ? c == 43712
                  : c <= 43714)))
              : (c <= 43741 || (c < 43777
                ? (c < 43762
                  ? (c >= 43744 && c <= 43754)
                  : c <= 43764)
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 55203
                  ? c == 44032
                  : c <= 55203)))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64467
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : c <= 64433)))
              : (c <= 64829 || (c < 65008
                ? (c < 64914
                  ? (c >= 64848 && c <= 64911)
                  : c <= 64967)
                : (c <= 65019 || (c < 65142
                  ? (c >= 65136 && c <= 65140)
                  : c <= 65276)))))))))
        : (c <= 65338 || (c < 66864
          ? (c < 66176
            ? (c < 65536
              ? (c < 65482
                ? (c < 65382
                  ? (c >= 65345 && c <= 65370)
                  : (c <= 65470 || (c >= 65474 && c <= 65479)))
                : (c <= 65487 || (c < 65498
                  ? (c >= 65490 && c <= 65495)
                  : c <= 65500)))
              : (c <= 65547 || (c < 65599
                ? (c < 65576
                  ? (c >= 65549 && c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))
                : (c <= 65613 || (c < 65664
                  ? (c >= 65616 && c <= 65629)
                  : c <= 65786)))))
            : (c <= 66204 || (c < 66464
              ? (c < 66370
                ? (c < 66304
                  ? (c >= 66208 && c <= 66256)
                  : (c <= 66335 || (c >= 66349 && c <= 66368)))
                : (c <= 66377 || (c < 66432
                  ? (c >= 66384 && c <= 66421)
                  : c <= 66461)))
              : (c <= 66499 || (c < 66736
                ? (c < 66560
                  ? (c >= 66504 && c <= 66511)
                  : c <= 66717)
                : (c <= 66771 || (c < 66816
                  ? (c >= 66776 && c <= 66811)
                  : c <= 66855)))))))
          : (c <= 66915 || (c < 67506
            ? (c < 66995
              ? (c < 66964
                ? (c < 66940
                  ? (c >= 66928 && c <= 66938)
                  : (c <= 66954 || (c >= 66956 && c <= 66962)))
                : (c <= 66965 || (c < 66979
                  ? (c >= 66967 && c <= 66977)
                  : c <= 66993)))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67680
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67808
                  ? (c >= 67712 && c <= 67742)
                  : c <= 67826)
                : (c <= 67829 || (c < 67872
                  ? (c >= 67840 && c <= 67861)
                  : c <= 67883)))))))))))))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(293);
      if (lookahead == '(') ADVANCE(15);
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '+') ADVANCE(303);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead == '.') ADVANCE(290);
      if (lookahead == ';') ADVANCE(295);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '`') ADVANCE(301);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(314);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(10)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(10)
      if (lookahead == '\r') SKIP(1)
      if (lookahead == '[') ADVANCE(18);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(11)
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(11)
      if (lookahead == '\r') SKIP(3)
      if (lookahead == '[') ADVANCE(18);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(7)
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\r') SKIP(5)
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(294);
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == '*') ADVANCE(84);
      if (lookahead == ';') ADVANCE(295);
      if (lookahead == '\\') SKIP(6)
      if (lookahead == '`') ADVANCE(301);
      if (lookahead == '\t' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(12)
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(12)
      if (lookahead == '\r') SKIP(8)
      if (lookahead == '[') ADVANCE(19);
      END_STATE();
    case 10:
      if (lookahead == '(') ADVANCE(15);
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '+') ADVANCE(303);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead == '.') ADVANCE(290);
      if (lookahead == ';') ADVANCE(295);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '`') ADVANCE(301);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(10)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(314);
      END_STATE();
    case 11:
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == '+') ADVANCE(303);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead == '.') ADVANCE(290);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '`') ADVANCE(300);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(11)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(314);
      END_STATE();
    case 12:
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(12)
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(314);
      END_STATE();
    case 13:
      if (lookahead == ')') ADVANCE(313);
      if (lookahead == '^') ADVANCE(302);
      END_STATE();
    case 14:
      if (lookahead == ')') ADVANCE(312);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(307);
      END_STATE();
    case 16:
      if (lookahead == '*') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '|') ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '*') ADVANCE(306);
      END_STATE();
    case 18:
      if (lookahead == 'A') ADVANCE(21);
      if (lookahead == 'B') ADVANCE(123);
      if (lookahead == 'C') ADVANCE(27);
      if (lookahead == 'D') ADVANCE(45);
      if (lookahead == 'E') ADVANCE(23);
      if (lookahead == 'F') ADVANCE(159);
      if (lookahead == 'G') ADVANCE(87);
      if (lookahead == 'H') ADVANCE(36);
      if (lookahead == 'I') ADVANCE(25);
      if (lookahead == 'K') ADVANCE(95);
      if (lookahead == 'L') ADVANCE(54);
      if (lookahead == 'M') ADVANCE(154);
      if (lookahead == 'N') ADVANCE(43);
      if (lookahead == 'O') ADVANCE(31);
      if (lookahead == 'P') ADVANCE(151);
      if (lookahead == 'R') ADVANCE(50);
      if (lookahead == 'S') ADVANCE(44);
      if (lookahead == 'T') ADVANCE(46);
      if (lookahead == 'U') ADVANCE(32);
      if (lookahead == 'W') ADVANCE(131);
      if (lookahead == 'X') ADVANCE(158);
      if (lookahead == 'Y') ADVANCE(29);
      if (lookahead == 'Z') ADVANCE(48);
      END_STATE();
    case 19:
      if (lookahead == 'A') ADVANCE(21);
      if (lookahead == 'B') ADVANCE(123);
      if (lookahead == 'C') ADVANCE(27);
      if (lookahead == 'D') ADVANCE(45);
      if (lookahead == 'E') ADVANCE(23);
      if (lookahead == 'F') ADVANCE(159);
      if (lookahead == 'G') ADVANCE(87);
      if (lookahead == 'H') ADVANCE(36);
      if (lookahead == 'I') ADVANCE(25);
      if (lookahead == 'K') ADVANCE(95);
      if (lookahead == 'L') ADVANCE(54);
      if (lookahead == 'M') ADVANCE(154);
      if (lookahead == 'N') ADVANCE(43);
      if (lookahead == 'O') ADVANCE(31);
      if (lookahead == 'P') ADVANCE(150);
      if (lookahead == 'R') ADVANCE(50);
      if (lookahead == 'S') ADVANCE(44);
      if (lookahead == 'T') ADVANCE(46);
      if (lookahead == 'U') ADVANCE(32);
      if (lookahead == 'W') ADVANCE(131);
      if (lookahead == 'X') ADVANCE(158);
      if (lookahead == 'Y') ADVANCE(29);
      if (lookahead == 'Z') ADVANCE(48);
      END_STATE();
    case 20:
      if (lookahead == 'A') ADVANCE(114);
      END_STATE();
    case 21:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'B') ADVANCE(96);
      if (lookahead == 'C') ADVANCE(279);
      if (lookahead == 'D') ADVANCE(215);
      if (lookahead == 'E') ADVANCE(60);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(93);
      if (lookahead == 'R') ADVANCE(162);
      if (lookahead == 'T') ADVANCE(163);
      if (lookahead == 'l') ADVANCE(134);
      if (lookahead == 'n') ADVANCE(142);
      END_STATE();
    case 22:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'B') ADVANCE(96);
      if (lookahead == 'C') ADVANCE(279);
      if (lookahead == 'D') ADVANCE(215);
      if (lookahead == 'E') ADVANCE(60);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(93);
      if (lookahead == 'R') ADVANCE(162);
      if (lookahead == 'T') ADVANCE(163);
      if (lookahead == 'l') ADVANCE(223);
      END_STATE();
    case 23:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'B') ADVANCE(96);
      if (lookahead == 'C') ADVANCE(279);
      if (lookahead == 'D') ADVANCE(215);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(88);
      if (lookahead == 'm') ADVANCE(227);
      if (lookahead == 'p') ADVANCE(258);
      if (lookahead == 't') ADVANCE(288);
      if (lookahead == 'x') ADVANCE(224);
      END_STATE();
    case 24:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'B') ADVANCE(96);
      if (lookahead == 'C') ADVANCE(279);
      if (lookahead == 'D') ADVANCE(215);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(88);
      if (lookahead == 'p') ADVANCE(258);
      if (lookahead == 't') ADVANCE(288);
      END_STATE();
    case 25:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'C') ADVANCE(279);
      if (lookahead == 'D') ADVANCE(215);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(93);
      if (lookahead == 'm') ADVANCE(92);
      if (lookahead == 'o') ADVANCE(268);
      END_STATE();
    case 26:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'C') ADVANCE(279);
      if (lookahead == 'D') ADVANCE(215);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(93);
      if (lookahead == 'o') ADVANCE(268);
      END_STATE();
    case 27:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'C') ADVANCE(124);
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'a') ADVANCE(226);
      if (lookahead == 'e') ADVANCE(207);
      if (lookahead == 'h') ADVANCE(158);
      if (lookahead == 'u') ADVANCE(239);
      END_STATE();
    case 28:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'C') ADVANCE(124);
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'h') ADVANCE(158);
      END_STATE();
    case 29:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'D') ADVANCE(215);
      if (lookahead == 'e') ADVANCE(206);
      END_STATE();
    case 30:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'D') ADVANCE(216);
      END_STATE();
    case 31:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'D') ADVANCE(219);
      if (lookahead == 'E') ADVANCE(60);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(93);
      if (lookahead == 'S') ADVANCE(194);
      if (lookahead == 'T') ADVANCE(163);
      if (lookahead == 'm') ADVANCE(140);
      END_STATE();
    case 32:
      if (lookahead == 'A') ADVANCE(114);
      if (lookahead == 'D') ADVANCE(219);
      if (lookahead == 'G') ADVANCE(242);
      if (lookahead == 'H') ADVANCE(93);
      if (lookahead == 'R') ADVANCE(162);
      if (lookahead == 'p') ADVANCE(258);
      END_STATE();
    case 33:
      if (lookahead == 'A') ADVANCE(76);
      if (lookahead == 'B') ADVANCE(69);
      if (lookahead == 'C') ADVANCE(67);
      if (lookahead == 'D') ADVANCE(70);
      if (lookahead == 'E') ADVANCE(81);
      if (lookahead == 'F') ADVANCE(75);
      if (lookahead == 'G') ADVANCE(62);
      if (lookahead == 'I') ADVANCE(78);
      if (lookahead == 'K') ADVANCE(65);
      if (lookahead == 'L') ADVANCE(64);
      if (lookahead == 'M') ADVANCE(82);
      if (lookahead == 'N') ADVANCE(82);
      if (lookahead == 'O') ADVANCE(77);
      if (lookahead == 'P') ADVANCE(72);
      if (lookahead == 'R') ADVANCE(73);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'T') ADVANCE(63);
      if (lookahead == 'U') ADVANCE(80);
      if (lookahead == 'X') ADVANCE(74);
      if (lookahead == 'Z') ADVANCE(69);
      if (('H' <= lookahead && lookahead <= 'Y')) ADVANCE(60);
      END_STATE();
    case 34:
      if (lookahead == 'A') ADVANCE(76);
      if (lookahead == 'B') ADVANCE(69);
      if (lookahead == 'C') ADVANCE(71);
      if (lookahead == 'D') ADVANCE(70);
      if (lookahead == 'E') ADVANCE(81);
      if (lookahead == 'G') ADVANCE(62);
      if (lookahead == 'I') ADVANCE(78);
      if (lookahead == 'K') ADVANCE(65);
      if (lookahead == 'L') ADVANCE(64);
      if (lookahead == 'M') ADVANCE(82);
      if (lookahead == 'N') ADVANCE(82);
      if (lookahead == 'O') ADVANCE(77);
      if (lookahead == 'P') ADVANCE(72);
      if (lookahead == 'R') ADVANCE(73);
      if (lookahead == 'S') ADVANCE(66);
      if (lookahead == 'T') ADVANCE(63);
      if (lookahead == 'U') ADVANCE(80);
      if (lookahead == 'X') ADVANCE(74);
      if (lookahead == 'Z') ADVANCE(69);
      if (('F' <= lookahead && lookahead <= 'Y')) ADVANCE(60);
      END_STATE();
    case 35:
      if (lookahead == 'A') ADVANCE(22);
      if (lookahead == 'B') ADVANCE(129);
      if (lookahead == 'C') ADVANCE(28);
      if (lookahead == 'D') ADVANCE(49);
      if (lookahead == 'E') ADVANCE(24);
      if (lookahead == 'G') ADVANCE(86);
      if (lookahead == 'I') ADVANCE(26);
      if (lookahead == 'K') ADVANCE(95);
      if (lookahead == 'L') ADVANCE(54);
      if (lookahead == 'M') ADVANCE(277);
      if (lookahead == 'N') ADVANCE(43);
      if (lookahead == 'O') ADVANCE(31);
      if (lookahead == 'P') ADVANCE(150);
      if (lookahead == 'R') ADVANCE(50);
      if (lookahead == 'S') ADVANCE(47);
      if (lookahead == 'T') ADVANCE(46);
      if (lookahead == 'U') ADVANCE(32);
      if (lookahead == 'X') ADVANCE(158);
      if (lookahead == 'Y') ADVANCE(20);
      if (lookahead == 'Z') ADVANCE(48);
      END_STATE();
    case 36:
      if (lookahead == 'B') ADVANCE(96);
      if (lookahead == 'a') ADVANCE(115);
      END_STATE();
    case 37:
      if (lookahead == 'C') ADVANCE(68);
      if (lookahead == 'D') ADVANCE(79);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(60);
      END_STATE();
    case 38:
      if (lookahead == 'C') ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(60);
      END_STATE();
    case 39:
      if (lookahead == 'C') ADVANCE(107);
      if (lookahead == 'E') ADVANCE(222);
      if (lookahead == 'K') ADVANCE(94);
      if (lookahead == 'P') ADVANCE(149);
      if (lookahead == 'R') ADVANCE(153);
      if (lookahead == 'T') ADVANCE(157);
      END_STATE();
    case 40:
      if (lookahead == 'D') ADVANCE(216);
      END_STATE();
    case 41:
      if (lookahead == 'E') ADVANCE(60);
      END_STATE();
    case 42:
      if (lookahead == 'G') ADVANCE(86);
      if (lookahead == 'P') ADVANCE(158);
      END_STATE();
    case 43:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'T') ADVANCE(163);
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 44:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'Z') ADVANCE(60);
      if (lookahead == 'a') ADVANCE(202);
      if (lookahead == 'c') ADVANCE(245);
      if (lookahead == 'i') ADVANCE(147);
      if (lookahead == 't') ADVANCE(139);
      END_STATE();
    case 45:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'a') ADVANCE(197);
      if (lookahead == 'e') ADVANCE(143);
      if (lookahead == 'i') ADVANCE(144);
      if (lookahead == 'o') ADVANCE(266);
      END_STATE();
    case 46:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'a') ADVANCE(277);
      if (lookahead == 'h') ADVANCE(130);
      END_STATE();
    case 47:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'a') ADVANCE(202);
      if (lookahead == 'i') ADVANCE(147);
      if (lookahead == 't') ADVANCE(161);
      END_STATE();
    case 48:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'e') ADVANCE(268);
      END_STATE();
    case 49:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'e') ADVANCE(189);
      if (lookahead == 'i') ADVANCE(144);
      END_STATE();
    case 50:
      if (lookahead == 'H') ADVANCE(90);
      if (lookahead == 'h') ADVANCE(213);
      END_STATE();
    case 51:
      if (lookahead == 'L') ADVANCE(167);
      if (lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 52:
      if (lookahead == 'L') ADVANCE(167);
      if (lookahead == 'o') ADVANCE(249);
      END_STATE();
    case 53:
      if (lookahead == 'P') ADVANCE(60);
      END_STATE();
    case 54:
      if (lookahead == 'S') ADVANCE(194);
      if (lookahead == 'a') ADVANCE(200);
      END_STATE();
    case 55:
      if (lookahead == 'S') ADVANCE(161);
      END_STATE();
    case 56:
      if (lookahead == 'S') ADVANCE(132);
      END_STATE();
    case 57:
      if (lookahead == 'S') ADVANCE(271);
      if (lookahead == 'd') ADVANCE(42);
      END_STATE();
    case 58:
      if (lookahead == 'U') ADVANCE(222);
      END_STATE();
    case 59:
      if (lookahead == '[') ADVANCE(19);
      END_STATE();
    case 60:
      if (lookahead == ']') ADVANCE(314);
      END_STATE();
    case 61:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 62:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(205);
      END_STATE();
    case 63:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(277);
      if (lookahead == 'h') ADVANCE(129);
      END_STATE();
    case 64:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(200);
      END_STATE();
    case 65:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(228);
      if (lookahead == 'o') ADVANCE(228);
      END_STATE();
    case 66:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(202);
      if (lookahead == 'i') ADVANCE(147);
      if (lookahead == 't') ADVANCE(161);
      END_STATE();
    case 67:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(232);
      if (lookahead == 'h') ADVANCE(158);
      if (lookahead == 'u') ADVANCE(239);
      END_STATE();
    case 68:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'a') ADVANCE(233);
      END_STATE();
    case 69:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'e') ADVANCE(268);
      END_STATE();
    case 70:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'e') ADVANCE(189);
      if (lookahead == 'i') ADVANCE(144);
      END_STATE();
    case 71:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'h') ADVANCE(158);
      END_STATE();
    case 72:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'h') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(60);
      if (lookahead == 's') ADVANCE(158);
      END_STATE();
    case 73:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'h') ADVANCE(213);
      END_STATE();
    case 74:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 75:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'i') ADVANCE(209);
      END_STATE();
    case 76:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'l') ADVANCE(223);
      END_STATE();
    case 77:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'm') ADVANCE(140);
      END_STATE();
    case 78:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'o') ADVANCE(268);
      END_STATE();
    case 79:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'o') ADVANCE(265);
      END_STATE();
    case 80:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'p') ADVANCE(258);
      END_STATE();
    case 81:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'p') ADVANCE(258);
      if (lookahead == 't') ADVANCE(85);
      END_STATE();
    case 82:
      if (lookahead == ']') ADVANCE(314);
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 83:
      if (lookahead == ']') ADVANCE(305);
      END_STATE();
    case 84:
      if (lookahead == '^') ADVANCE(302);
      END_STATE();
    case 85:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 86:
      if (lookahead == 'a') ADVANCE(205);
      END_STATE();
    case 87:
      if (lookahead == 'a') ADVANCE(205);
      if (lookahead == 'i') ADVANCE(201);
      if (lookahead == 'o') ADVANCE(262);
      END_STATE();
    case 88:
      if (lookahead == 'a') ADVANCE(116);
      END_STATE();
    case 89:
      if (lookahead == 'a') ADVANCE(284);
      END_STATE();
    case 90:
      if (lookahead == 'a') ADVANCE(115);
      END_STATE();
    case 91:
      if (lookahead == 'a') ADVANCE(253);
      END_STATE();
    case 92:
      if (lookahead == 'a') ADVANCE(148);
      END_STATE();
    case 93:
      if (lookahead == 'a') ADVANCE(259);
      END_STATE();
    case 94:
      if (lookahead == 'a') ADVANCE(228);
      END_STATE();
    case 95:
      if (lookahead == 'a') ADVANCE(228);
      if (lookahead == 'o') ADVANCE(228);
      END_STATE();
    case 96:
      if (lookahead == 'a') ADVANCE(234);
      END_STATE();
    case 97:
      if (lookahead == 'a') ADVANCE(188);
      END_STATE();
    case 98:
      if (lookahead == 'a') ADVANCE(264);
      END_STATE();
    case 99:
      if (lookahead == 'a') ADVANCE(180);
      END_STATE();
    case 100:
      if (lookahead == 'a') ADVANCE(181);
      END_STATE();
    case 101:
      if (lookahead == 'a') ADVANCE(237);
      END_STATE();
    case 102:
      if (lookahead == 'a') ADVANCE(182);
      END_STATE();
    case 103:
      if (lookahead == 'a') ADVANCE(183);
      END_STATE();
    case 104:
      if (lookahead == 'a') ADVANCE(184);
      END_STATE();
    case 105:
      if (lookahead == 'a') ADVANCE(185);
      END_STATE();
    case 106:
      if (lookahead == 'a') ADVANCE(255);
      END_STATE();
    case 107:
      if (lookahead == 'a') ADVANCE(231);
      END_STATE();
    case 108:
      if (lookahead == 'b') ADVANCE(120);
      END_STATE();
    case 109:
      if (lookahead == 'b') ADVANCE(193);
      END_STATE();
    case 110:
      if (lookahead == 'b') ADVANCE(195);
      END_STATE();
    case 111:
      if (lookahead == 'b') ADVANCE(196);
      END_STATE();
    case 112:
      if (lookahead == 'c') ADVANCE(38);
      END_STATE();
    case 113:
      if (lookahead == 'c') ADVANCE(177);
      END_STATE();
    case 114:
      if (lookahead == 'c') ADVANCE(280);
      END_STATE();
    case 115:
      if (lookahead == 'c') ADVANCE(125);
      END_STATE();
    case 116:
      if (lookahead == 'c') ADVANCE(125);
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 117:
      if (lookahead == 'c') ADVANCE(235);
      END_STATE();
    case 118:
      if (lookahead == 'c') ADVANCE(238);
      END_STATE();
    case 119:
      if (lookahead == 'd') ADVANCE(122);
      END_STATE();
    case 120:
      if (lookahead == 'd') ADVANCE(85);
      END_STATE();
    case 121:
      if (lookahead == 'd') ADVANCE(169);
      END_STATE();
    case 122:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 123:
      if (lookahead == 'e') ADVANCE(260);
      END_STATE();
    case 124:
      if (lookahead == 'e') ADVANCE(121);
      END_STATE();
    case 125:
      if (lookahead == 'e') ADVANCE(176);
      END_STATE();
    case 126:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 127:
      if (lookahead == 'e') ADVANCE(40);
      END_STATE();
    case 128:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 129:
      if (lookahead == 'e') ADVANCE(268);
      END_STATE();
    case 130:
      if (lookahead == 'e') ADVANCE(268);
      if (lookahead == 'o') ADVANCE(236);
      END_STATE();
    case 131:
      if (lookahead == 'e') ADVANCE(166);
      END_STATE();
    case 132:
      if (lookahead == 'e') ADVANCE(259);
      END_STATE();
    case 133:
      if (lookahead == 'e') ADVANCE(254);
      END_STATE();
    case 134:
      if (lookahead == 'e') ADVANCE(225);
      if (lookahead == 'p') ADVANCE(156);
      END_STATE();
    case 135:
      if (lookahead == 'e') ADVANCE(178);
      END_STATE();
    case 136:
      if (lookahead == 'e') ADVANCE(122);
      END_STATE();
    case 137:
      if (lookahead == 'e') ADVANCE(250);
      END_STATE();
    case 138:
      if (lookahead == 'e') ADVANCE(211);
      END_STATE();
    case 139:
      if (lookahead == 'e') ADVANCE(247);
      if (lookahead == 'i') ADVANCE(147);
      END_STATE();
    case 140:
      if (lookahead == 'e') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(118);
      END_STATE();
    case 141:
      if (lookahead == 'g') ADVANCE(60);
      END_STATE();
    case 142:
      if (lookahead == 'g') ADVANCE(256);
      END_STATE();
    case 143:
      if (lookahead == 'g') ADVANCE(244);
      if (lookahead == 'l') ADVANCE(268);
      END_STATE();
    case 144:
      if (lookahead == 'g') ADVANCE(86);
      END_STATE();
    case 145:
      if (lookahead == 'g') ADVANCE(85);
      END_STATE();
    case 146:
      if (lookahead == 'g') ADVANCE(98);
      END_STATE();
    case 147:
      if (lookahead == 'g') ADVANCE(203);
      END_STATE();
    case 148:
      if (lookahead == 'g') ADVANCE(165);
      END_STATE();
    case 149:
      if (lookahead == 'h') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 150:
      if (lookahead == 'h') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(60);
      if (lookahead == 's') ADVANCE(158);
      END_STATE();
    case 151:
      if (lookahead == 'h') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(83);
      if (lookahead == 's') ADVANCE(158);
      END_STATE();
    case 152:
      if (lookahead == 'h') ADVANCE(60);
      END_STATE();
    case 153:
      if (lookahead == 'h') ADVANCE(213);
      END_STATE();
    case 154:
      if (lookahead == 'h') ADVANCE(213);
      if (lookahead == 'i') ADVANCE(117);
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 155:
      if (lookahead == 'h') ADVANCE(164);
      END_STATE();
    case 156:
      if (lookahead == 'h') ADVANCE(85);
      END_STATE();
    case 157:
      if (lookahead == 'h') ADVANCE(129);
      END_STATE();
    case 158:
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 159:
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 'l') ADVANCE(52);
      if (lookahead == 'o') ADVANCE(241);
      END_STATE();
    case 160:
      if (lookahead == 'i') ADVANCE(206);
      END_STATE();
    case 161:
      if (lookahead == 'i') ADVANCE(147);
      END_STATE();
    case 162:
      if (lookahead == 'i') ADVANCE(208);
      END_STATE();
    case 163:
      if (lookahead == 'i') ADVANCE(187);
      END_STATE();
    case 164:
      if (lookahead == 'i') ADVANCE(112);
      END_STATE();
    case 165:
      if (lookahead == 'i') ADVANCE(212);
      END_STATE();
    case 166:
      if (lookahead == 'i') ADVANCE(137);
      END_STATE();
    case 167:
      if (lookahead == 'i') ADVANCE(146);
      END_STATE();
    case 168:
      if (lookahead == 'i') ADVANCE(190);
      END_STATE();
    case 169:
      if (lookahead == 'i') ADVANCE(198);
      END_STATE();
    case 170:
      if (lookahead == 'i') ADVANCE(229);
      END_STATE();
    case 171:
      if (lookahead == 'i') ADVANCE(273);
      END_STATE();
    case 172:
      if (lookahead == 'i') ADVANCE(102);
      END_STATE();
    case 173:
      if (lookahead == 'i') ADVANCE(274);
      END_STATE();
    case 174:
      if (lookahead == 'i') ADVANCE(275);
      END_STATE();
    case 175:
      if (lookahead == 'i') ADVANCE(276);
      END_STATE();
    case 176:
      if (lookahead == 'k') ADVANCE(60);
      END_STATE();
    case 177:
      if (lookahead == 'k') ADVANCE(38);
      END_STATE();
    case 178:
      if (lookahead == 'l') ADVANCE(60);
      END_STATE();
    case 179:
      if (lookahead == 'l') ADVANCE(285);
      END_STATE();
    case 180:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 181:
      if (lookahead == 'l') ADVANCE(35);
      END_STATE();
    case 182:
      if (lookahead == 'l') ADVANCE(41);
      END_STATE();
    case 183:
      if (lookahead == 'l') ADVANCE(58);
      END_STATE();
    case 184:
      if (lookahead == 'l') ADVANCE(34);
      END_STATE();
    case 185:
      if (lookahead == 'l') ADVANCE(291);
      END_STATE();
    case 186:
      if (lookahead == 'l') ADVANCE(162);
      END_STATE();
    case 187:
      if (lookahead == 'l') ADVANCE(119);
      END_STATE();
    case 188:
      if (lookahead == 'l') ADVANCE(55);
      END_STATE();
    case 189:
      if (lookahead == 'l') ADVANCE(268);
      END_STATE();
    case 190:
      if (lookahead == 'l') ADVANCE(214);
      END_STATE();
    case 191:
      if (lookahead == 'l') ADVANCE(133);
      END_STATE();
    case 192:
      if (lookahead == 'l') ADVANCE(85);
      END_STATE();
    case 193:
      if (lookahead == 'l') ADVANCE(126);
      END_STATE();
    case 194:
      if (lookahead == 'l') ADVANCE(91);
      END_STATE();
    case 195:
      if (lookahead == 'l') ADVANCE(127);
      END_STATE();
    case 196:
      if (lookahead == 'l') ADVANCE(128);
      END_STATE();
    case 197:
      if (lookahead == 'l') ADVANCE(132);
      END_STATE();
    case 198:
      if (lookahead == 'l') ADVANCE(192);
      END_STATE();
    case 199:
      if (lookahead == 'm') ADVANCE(60);
      END_STATE();
    case 200:
      if (lookahead == 'm') ADVANCE(108);
      END_STATE();
    case 201:
      if (lookahead == 'm') ADVANCE(135);
      END_STATE();
    case 202:
      if (lookahead == 'm') ADVANCE(220);
      END_STATE();
    case 203:
      if (lookahead == 'm') ADVANCE(85);
      END_STATE();
    case 204:
      if (lookahead == 'm') ADVANCE(99);
      END_STATE();
    case 205:
      if (lookahead == 'm') ADVANCE(203);
      END_STATE();
    case 206:
      if (lookahead == 'n') ADVANCE(60);
      END_STATE();
    case 207:
      if (lookahead == 'n') ADVANCE(259);
      END_STATE();
    case 208:
      if (lookahead == 'n') ADVANCE(141);
      END_STATE();
    case 209:
      if (lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 210:
      if (lookahead == 'n') ADVANCE(138);
      END_STATE();
    case 211:
      if (lookahead == 'n') ADVANCE(269);
      END_STATE();
    case 212:
      if (lookahead == 'n') ADVANCE(101);
      END_STATE();
    case 213:
      if (lookahead == 'o') ADVANCE(60);
      END_STATE();
    case 214:
      if (lookahead == 'o') ADVANCE(206);
      END_STATE();
    case 215:
      if (lookahead == 'o') ADVANCE(282);
      END_STATE();
    case 216:
      if (lookahead == 'o') ADVANCE(259);
      END_STATE();
    case 217:
      if (lookahead == 'o') ADVANCE(210);
      END_STATE();
    case 218:
      if (lookahead == 'o') ADVANCE(199);
      END_STATE();
    case 219:
      if (lookahead == 'o') ADVANCE(283);
      END_STATE();
    case 220:
      if (lookahead == 'p') ADVANCE(158);
      END_STATE();
    case 221:
      if (lookahead == 'p') ADVANCE(60);
      END_STATE();
    case 222:
      if (lookahead == 'p') ADVANCE(258);
      END_STATE();
    case 223:
      if (lookahead == 'p') ADVANCE(156);
      END_STATE();
    case 224:
      if (lookahead == 'p') ADVANCE(217);
      END_STATE();
    case 225:
      if (lookahead == 'p') ADVANCE(152);
      END_STATE();
    case 226:
      if (lookahead == 'p') ADVANCE(171);
      END_STATE();
    case 227:
      if (lookahead == 'p') ADVANCE(263);
      END_STATE();
    case 228:
      if (lookahead == 'p') ADVANCE(230);
      END_STATE();
    case 229:
      if (lookahead == 'p') ADVANCE(261);
      END_STATE();
    case 230:
      if (lookahead == 'p') ADVANCE(85);
      END_STATE();
    case 231:
      if (lookahead == 'p') ADVANCE(173);
      END_STATE();
    case 232:
      if (lookahead == 'p') ADVANCE(174);
      END_STATE();
    case 233:
      if (lookahead == 'p') ADVANCE(175);
      END_STATE();
    case 234:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 235:
      if (lookahead == 'r') ADVANCE(213);
      END_STATE();
    case 236:
      if (lookahead == 'r') ADVANCE(206);
      END_STATE();
    case 237:
      if (lookahead == 'r') ADVANCE(287);
      END_STATE();
    case 238:
      if (lookahead == 'r') ADVANCE(214);
      END_STATE();
    case 239:
      if (lookahead == 'r') ADVANCE(179);
      END_STATE();
    case 240:
      if (lookahead == 'r') ADVANCE(218);
      END_STATE();
    case 241:
      if (lookahead == 'r') ADVANCE(204);
      END_STATE();
    case 242:
      if (lookahead == 'r') ADVANCE(89);
      END_STATE();
    case 243:
      if (lookahead == 'r') ADVANCE(278);
      END_STATE();
    case 244:
      if (lookahead == 'r') ADVANCE(136);
      END_STATE();
    case 245:
      if (lookahead == 'r') ADVANCE(170);
      END_STATE();
    case 246:
      if (lookahead == 'r') ADVANCE(122);
      END_STATE();
    case 247:
      if (lookahead == 'r') ADVANCE(186);
      END_STATE();
    case 248:
      if (lookahead == 'r') ADVANCE(106);
      END_STATE();
    case 249:
      if (lookahead == 'r') ADVANCE(160);
      END_STATE();
    case 250:
      if (lookahead == 'r') ADVANCE(257);
      END_STATE();
    case 251:
      if (lookahead == 's') ADVANCE(289);
      END_STATE();
    case 252:
      if (lookahead == 's') ADVANCE(53);
      END_STATE();
    case 253:
      if (lookahead == 's') ADVANCE(152);
      END_STATE();
    case 254:
      if (lookahead == 's') ADVANCE(251);
      END_STATE();
    case 255:
      if (lookahead == 's') ADVANCE(252);
      END_STATE();
    case 256:
      if (lookahead == 's') ADVANCE(270);
      END_STATE();
    case 257:
      if (lookahead == 's') ADVANCE(272);
      END_STATE();
    case 258:
      if (lookahead == 's') ADVANCE(168);
      END_STATE();
    case 259:
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 260:
      if (lookahead == 't') ADVANCE(61);
      END_STATE();
    case 261:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 262:
      if (lookahead == 't') ADVANCE(155);
      END_STATE();
    case 263:
      if (lookahead == 't') ADVANCE(286);
      END_STATE();
    case 264:
      if (lookahead == 't') ADVANCE(281);
      END_STATE();
    case 265:
      if (lookahead == 't') ADVANCE(191);
      END_STATE();
    case 266:
      if (lookahead == 't') ADVANCE(191);
      if (lookahead == 'u') ADVANCE(109);
      END_STATE();
    case 267:
      if (lookahead == 't') ADVANCE(122);
      END_STATE();
    case 268:
      if (lookahead == 't') ADVANCE(85);
      END_STATE();
    case 269:
      if (lookahead == 't') ADVANCE(172);
      END_STATE();
    case 270:
      if (lookahead == 't') ADVANCE(240);
      END_STATE();
    case 271:
      if (lookahead == 't') ADVANCE(243);
      END_STATE();
    case 272:
      if (lookahead == 't') ADVANCE(248);
      END_STATE();
    case 273:
      if (lookahead == 't') ADVANCE(100);
      END_STATE();
    case 274:
      if (lookahead == 't') ADVANCE(103);
      END_STATE();
    case 275:
      if (lookahead == 't') ADVANCE(104);
      END_STATE();
    case 276:
      if (lookahead == 't') ADVANCE(105);
      END_STATE();
    case 277:
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 278:
      if (lookahead == 'u') ADVANCE(113);
      END_STATE();
    case 279:
      if (lookahead == 'u') ADVANCE(221);
      END_STATE();
    case 280:
      if (lookahead == 'u') ADVANCE(267);
      END_STATE();
    case 281:
      if (lookahead == 'u') ADVANCE(246);
      END_STATE();
    case 282:
      if (lookahead == 'u') ADVANCE(110);
      END_STATE();
    case 283:
      if (lookahead == 'u') ADVANCE(111);
      END_STATE();
    case 284:
      if (lookahead == 'v') ADVANCE(122);
      END_STATE();
    case 285:
      if (lookahead == 'y') ADVANCE(39);
      END_STATE();
    case 286:
      if (lookahead == 'y') ADVANCE(56);
      END_STATE();
    case 287:
      if (lookahead == 'y') ADVANCE(289);
      END_STATE();
    case 288:
      if (lookahead == 'a' ||
          lookahead == 'h') ADVANCE(60);
      END_STATE();
    case 289:
      if (lookahead == 'I' ||
          lookahead == 'J') ADVANCE(60);
      END_STATE();
    case 290:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      END_STATE();
    case 291:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(60);
      END_STATE();
    case 292:
      if (eof) ADVANCE(293);
      if (lookahead == '(') ADVANCE(17);
      if (lookahead == '+') ADVANCE(303);
      if (lookahead == '-') ADVANCE(304);
      if (lookahead == '.') ADVANCE(290);
      if (lookahead == '\\') ADVANCE(4);
      if (lookahead == '`') ADVANCE(300);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(292)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(314);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(294);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(aux_sym_number_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(297);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(aux_sym_number_token3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_BQUOTE_BQUOTE);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead == '`') ADVANCE(299);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_STAR_CARET);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_BSLASH_LBRACKPi_RBRACK);
      if (lookahead == '\\') ADVANCE(59);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(314);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_LPAREN_STAR);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(anon_sym_LPAREN_STAR);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '|') ADVANCE(16);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\n') ADVANCE(310);
      if (lookahead == '\r') ADVANCE(309);
      if (lookahead != 0 &&
          (lookahead < '(' || '*' < lookahead) &&
          lookahead != '|') ADVANCE(311);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\n') ADVANCE(310);
      if (lookahead != 0 &&
          (lookahead < '(' || '*' < lookahead) &&
          lookahead != '|') ADVANCE(311);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\\') ADVANCE(308);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) ADVANCE(310);
      if (lookahead != 0 &&
          (lookahead < '(' || '*' < lookahead) &&
          lookahead != '|') ADVANCE(311);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          (lookahead < '(' || '*' < lookahead) &&
          lookahead != '|') ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_STAR_RPAREN);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '\\') ADVANCE(59);
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(314);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'E') ADVANCE(1);
      if (lookahead == 'F') ADVANCE(2);
      if (lookahead == 'I') ADVANCE(3);
      if (lookahead == 'N') ADVANCE(4);
      if (lookahead == 'P') ADVANCE(5);
      if (lookahead == 'T') ADVANCE(6);
      if (lookahead == '\\') SKIP(7)
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\f' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'x') ADVANCE(8);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(9);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_I);
      if (lookahead == 'm') ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 5:
      if (lookahead == 'i') ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(14)
      END_STATE();
    case 8:
      if (lookahead == 'p') ADVANCE(15);
      END_STATE();
    case 9:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(17);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_Pi);
      END_STATE();
    case 13:
      if (lookahead == 'u') ADVANCE(19);
      END_STATE();
    case 14:
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 16:
      if (lookahead == 's') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'g') ADVANCE(22);
      END_STATE();
    case 18:
      if (lookahead == 'l') ADVANCE(23);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 20:
      if (lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(26);
      END_STATE();
    case 22:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_Null);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_True);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_False);
      END_STATE();
    case 27:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 28:
      if (lookahead == 'n') ADVANCE(30);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 30:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 32:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 33:
      if (lookahead == 'y') ADVANCE(35);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 35:
      if (lookahead == 'I') ADVANCE(37);
      if (lookahead == 'J') ADVANCE(38);
      END_STATE();
    case 36:
      if (lookahead == 'l') ADVANCE(39);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_ImaginaryI);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_ImaginaryJ);
      END_STATE();
    case 39:
      if (lookahead == 'E') ADVANCE(40);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_ExponentialE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 292},
  [2] = {.lex_state = 292},
  [3] = {.lex_state = 292},
  [4] = {.lex_state = 292},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 292},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 7},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 7},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 292},
  [15] = {.lex_state = 292},
  [16] = {.lex_state = 7},
  [17] = {.lex_state = 7},
  [18] = {.lex_state = 7},
  [19] = {.lex_state = 7},
  [20] = {.lex_state = 7},
  [21] = {.lex_state = 12},
  [22] = {.lex_state = 12},
  [23] = {.lex_state = 12},
  [24] = {.lex_state = 7},
  [25] = {.lex_state = 7},
  [26] = {.lex_state = 7},
  [27] = {.lex_state = 12},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 292},
  [30] = {.lex_state = 292},
  [31] = {.lex_state = 310},
  [32] = {.lex_state = 292},
  [33] = {.lex_state = 310},
  [34] = {.lex_state = 292},
  [35] = {.lex_state = 12},
  [36] = {(TSStateId)(-1)},
  [37] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [aux_sym_number_token1] = ACTIONS(1),
    [aux_sym_number_token2] = ACTIONS(1),
    [aux_sym_number_token3] = ACTIONS(1),
    [anon_sym_BQUOTE_BQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_STAR_CARET] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_True] = ACTIONS(1),
    [anon_sym_False] = ACTIONS(1),
    [anon_sym_Null] = ACTIONS(1),
    [anon_sym_I] = ACTIONS(1),
    [anon_sym_ImaginaryI] = ACTIONS(1),
    [anon_sym_ImaginaryJ] = ACTIONS(1),
    [anon_sym_ExponentialE] = ACTIONS(1),
    [anon_sym_Pi] = ACTIONS(1),
    [anon_sym_BSLASH_LBRACKPi_RBRACK] = ACTIONS(1),
    [anon_sym_LPAREN_STAR] = ACTIONS(3),
    [aux_sym_comment_token2] = ACTIONS(1),
    [anon_sym_STAR_RPAREN] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(29),
    [sym_expression] = STATE(17),
    [sym_atomic] = STATE(26),
    [sym_number] = STATE(25),
    [sym_builtin_symbol] = STATE(25),
    [sym_scoped_symbol] = STATE(25),
    [sym__symbol] = STATE(25),
    [sym_comment] = STATE(1),
    [aux_sym_source_file_repeat1] = STATE(2),
    [aux_sym_scoped_symbol_repeat1] = STATE(21),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [aux_sym_number_token1] = ACTIONS(9),
    [aux_sym_number_token2] = ACTIONS(11),
    [aux_sym_number_token3] = ACTIONS(9),
    [anon_sym_BQUOTE] = ACTIONS(13),
    [anon_sym_True] = ACTIONS(15),
    [anon_sym_False] = ACTIONS(15),
    [anon_sym_Null] = ACTIONS(15),
    [anon_sym_I] = ACTIONS(15),
    [anon_sym_ImaginaryI] = ACTIONS(15),
    [anon_sym_ImaginaryJ] = ACTIONS(15),
    [anon_sym_ExponentialE] = ACTIONS(15),
    [anon_sym_Pi] = ACTIONS(15),
    [anon_sym_BSLASH_LBRACKPi_RBRACK] = ACTIONS(15),
    [anon_sym_LPAREN_STAR] = ACTIONS(17),
  },
  [2] = {
    [sym_expression] = STATE(17),
    [sym_atomic] = STATE(26),
    [sym_number] = STATE(25),
    [sym_builtin_symbol] = STATE(25),
    [sym_scoped_symbol] = STATE(25),
    [sym__symbol] = STATE(25),
    [sym_comment] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(3),
    [aux_sym_scoped_symbol_repeat1] = STATE(21),
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym_identifier] = ACTIONS(7),
    [aux_sym_number_token1] = ACTIONS(9),
    [aux_sym_number_token2] = ACTIONS(11),
    [aux_sym_number_token3] = ACTIONS(9),
    [anon_sym_BQUOTE] = ACTIONS(13),
    [anon_sym_True] = ACTIONS(15),
    [anon_sym_False] = ACTIONS(15),
    [anon_sym_Null] = ACTIONS(15),
    [anon_sym_I] = ACTIONS(15),
    [anon_sym_ImaginaryI] = ACTIONS(15),
    [anon_sym_ImaginaryJ] = ACTIONS(15),
    [anon_sym_ExponentialE] = ACTIONS(15),
    [anon_sym_Pi] = ACTIONS(15),
    [anon_sym_BSLASH_LBRACKPi_RBRACK] = ACTIONS(15),
    [anon_sym_LPAREN_STAR] = ACTIONS(17),
  },
  [3] = {
    [sym_expression] = STATE(17),
    [sym_atomic] = STATE(26),
    [sym_number] = STATE(25),
    [sym_builtin_symbol] = STATE(25),
    [sym_scoped_symbol] = STATE(25),
    [sym__symbol] = STATE(25),
    [sym_comment] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [aux_sym_scoped_symbol_repeat1] = STATE(21),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_identifier] = ACTIONS(23),
    [aux_sym_number_token1] = ACTIONS(26),
    [aux_sym_number_token2] = ACTIONS(29),
    [aux_sym_number_token3] = ACTIONS(26),
    [anon_sym_BQUOTE] = ACTIONS(32),
    [anon_sym_True] = ACTIONS(35),
    [anon_sym_False] = ACTIONS(35),
    [anon_sym_Null] = ACTIONS(35),
    [anon_sym_I] = ACTIONS(35),
    [anon_sym_ImaginaryI] = ACTIONS(35),
    [anon_sym_ImaginaryJ] = ACTIONS(35),
    [anon_sym_ExponentialE] = ACTIONS(35),
    [anon_sym_Pi] = ACTIONS(35),
    [anon_sym_BSLASH_LBRACKPi_RBRACK] = ACTIONS(35),
    [anon_sym_LPAREN_STAR] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    STATE(4), 1,
      sym_comment,
    ACTIONS(21), 3,
      ts_builtin_sym_end,
      aux_sym_number_token2,
      anon_sym_BQUOTE,
    ACTIONS(38), 12,
      aux_sym_number_token1,
      aux_sym_number_token3,
      anon_sym_True,
      anon_sym_False,
      anon_sym_Null,
      anon_sym_I,
      anon_sym_ImaginaryI,
      anon_sym_ImaginaryJ,
      anon_sym_ExponentialE,
      anon_sym_Pi,
      anon_sym_BSLASH_LBRACKPi_RBRACK,
      sym_identifier,
  [26] = 6,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(40), 1,
      anon_sym_LF,
    ACTIONS(42), 1,
      anon_sym_SEMI,
    ACTIONS(46), 1,
      anon_sym_STAR_CARET,
    STATE(5), 1,
      sym_comment,
    ACTIONS(44), 2,
      anon_sym_BQUOTE_BQUOTE,
      anon_sym_BQUOTE,
  [46] = 4,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(48), 1,
      aux_sym_number_token1,
    STATE(6), 1,
      sym_comment,
    ACTIONS(50), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [60] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(52), 1,
      aux_sym_comment_token2,
    ACTIONS(55), 1,
      anon_sym_STAR_RPAREN,
    STATE(7), 2,
      sym_comment,
      aux_sym_comment_repeat1,
  [74] = 5,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(57), 1,
      anon_sym_LF,
    ACTIONS(59), 1,
      anon_sym_SEMI,
    ACTIONS(61), 1,
      anon_sym_BQUOTE,
    STATE(8), 1,
      sym_comment,
  [90] = 5,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(61), 1,
      anon_sym_BQUOTE,
    ACTIONS(63), 1,
      anon_sym_LF,
    ACTIONS(65), 1,
      anon_sym_SEMI,
    STATE(9), 1,
      sym_comment,
  [106] = 5,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(67), 1,
      anon_sym_LF,
    ACTIONS(69), 1,
      anon_sym_SEMI,
    ACTIONS(71), 1,
      anon_sym_STAR_CARET,
    STATE(10), 1,
      sym_comment,
  [122] = 5,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(73), 1,
      aux_sym_comment_token2,
    ACTIONS(75), 1,
      anon_sym_STAR_RPAREN,
    STATE(7), 1,
      aux_sym_comment_repeat1,
    STATE(11), 1,
      sym_comment,
  [138] = 5,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(61), 1,
      anon_sym_BQUOTE,
    ACTIONS(77), 1,
      anon_sym_LF,
    ACTIONS(79), 1,
      anon_sym_SEMI,
    STATE(12), 1,
      sym_comment,
  [154] = 5,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(73), 1,
      aux_sym_comment_token2,
    ACTIONS(81), 1,
      anon_sym_STAR_RPAREN,
    STATE(11), 1,
      aux_sym_comment_repeat1,
    STATE(13), 1,
      sym_comment,
  [170] = 4,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(85), 1,
      aux_sym_number_token2,
    STATE(14), 1,
      sym_comment,
    ACTIONS(83), 2,
      aux_sym_number_token1,
      aux_sym_number_token3,
  [184] = 4,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(87), 1,
      aux_sym_number_token1,
    STATE(15), 1,
      sym_comment,
    ACTIONS(89), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
  [198] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(67), 1,
      anon_sym_LF,
    ACTIONS(69), 1,
      anon_sym_SEMI,
    STATE(16), 1,
      sym_comment,
  [211] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(91), 1,
      anon_sym_LF,
    ACTIONS(93), 1,
      anon_sym_SEMI,
    STATE(17), 1,
      sym_comment,
  [224] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(95), 1,
      anon_sym_LF,
    ACTIONS(97), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym_comment,
  [237] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(99), 1,
      anon_sym_LF,
    ACTIONS(101), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      sym_comment,
  [250] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(103), 1,
      anon_sym_LF,
    ACTIONS(105), 1,
      anon_sym_SEMI,
    STATE(20), 1,
      sym_comment,
  [263] = 4,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(107), 1,
      sym_identifier,
    STATE(21), 1,
      sym_comment,
    STATE(22), 1,
      aux_sym_scoped_symbol_repeat1,
  [276] = 3,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(109), 1,
      sym_identifier,
    STATE(22), 2,
      sym_comment,
      aux_sym_scoped_symbol_repeat1,
  [287] = 4,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(112), 1,
      sym_identifier,
    STATE(23), 1,
      sym_comment,
    STATE(27), 1,
      aux_sym_scoped_symbol_repeat1,
  [300] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(114), 1,
      anon_sym_LF,
    ACTIONS(116), 1,
      anon_sym_SEMI,
    STATE(24), 1,
      sym_comment,
  [313] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(118), 1,
      anon_sym_LF,
    ACTIONS(120), 1,
      anon_sym_SEMI,
    STATE(25), 1,
      sym_comment,
  [326] = 4,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(122), 1,
      anon_sym_LF,
    ACTIONS(124), 1,
      anon_sym_SEMI,
    STATE(26), 1,
      sym_comment,
  [339] = 4,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(126), 1,
      sym_identifier,
    STATE(22), 1,
      aux_sym_scoped_symbol_repeat1,
    STATE(27), 1,
      sym_comment,
  [352] = 3,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    STATE(28), 1,
      sym_comment,
    ACTIONS(55), 2,
      aux_sym_comment_token2,
      anon_sym_STAR_RPAREN,
  [363] = 3,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(128), 1,
      ts_builtin_sym_end,
    STATE(29), 1,
      sym_comment,
  [373] = 3,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(130), 1,
      aux_sym_number_token1,
    STATE(30), 1,
      sym_comment,
  [383] = 3,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(132), 1,
      aux_sym_comment_token1,
    STATE(31), 1,
      sym_comment,
  [393] = 3,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(134), 1,
      anon_sym_BQUOTE,
    STATE(32), 1,
      sym_comment,
  [403] = 3,
    ACTIONS(3), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(136), 1,
      aux_sym_comment_token1,
    STATE(33), 1,
      sym_comment,
  [413] = 3,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(138), 1,
      aux_sym_number_token1,
    STATE(34), 1,
      sym_comment,
  [423] = 3,
    ACTIONS(17), 1,
      anon_sym_LPAREN_STAR,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(35), 1,
      sym_comment,
  [433] = 1,
    ACTIONS(142), 1,
      ts_builtin_sym_end,
  [437] = 1,
    ACTIONS(144), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 26,
  [SMALL_STATE(6)] = 46,
  [SMALL_STATE(7)] = 60,
  [SMALL_STATE(8)] = 74,
  [SMALL_STATE(9)] = 90,
  [SMALL_STATE(10)] = 106,
  [SMALL_STATE(11)] = 122,
  [SMALL_STATE(12)] = 138,
  [SMALL_STATE(13)] = 154,
  [SMALL_STATE(14)] = 170,
  [SMALL_STATE(15)] = 184,
  [SMALL_STATE(16)] = 198,
  [SMALL_STATE(17)] = 211,
  [SMALL_STATE(18)] = 224,
  [SMALL_STATE(19)] = 237,
  [SMALL_STATE(20)] = 250,
  [SMALL_STATE(21)] = 263,
  [SMALL_STATE(22)] = 276,
  [SMALL_STATE(23)] = 287,
  [SMALL_STATE(24)] = 300,
  [SMALL_STATE(25)] = 313,
  [SMALL_STATE(26)] = 326,
  [SMALL_STATE(27)] = 339,
  [SMALL_STATE(28)] = 352,
  [SMALL_STATE(29)] = 363,
  [SMALL_STATE(30)] = 373,
  [SMALL_STATE(31)] = 383,
  [SMALL_STATE(32)] = 393,
  [SMALL_STATE(33)] = 403,
  [SMALL_STATE(34)] = 413,
  [SMALL_STATE(35)] = 423,
  [SMALL_STATE(36)] = 433,
  [SMALL_STATE(37)] = 437,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(23),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(24),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 1),
  [44] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_comment_repeat1, 2), SHIFT_REPEAT(31),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_comment_repeat1, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scoped_symbol, 3, .production_id = 2),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scoped_symbol, 3, .production_id = 2),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__symbol, 1),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__symbol, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 3),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 3),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_scoped_symbol, 2, .production_id = 1),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_scoped_symbol, 2, .production_id = 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 6),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 6),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 5),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 5),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 4),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 4),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_scoped_symbol_repeat1, 2), SHIFT_REPEAT(32),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_builtin_symbol, 1),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_builtin_symbol, 1),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_atomic, 1),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_atomic, 1),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [128] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_scoped_symbol_repeat1, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 4),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_wolfram(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
