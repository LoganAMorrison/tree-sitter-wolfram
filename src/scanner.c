#include <tree_sitter/parser.h>
#include <wchar.h>
#include <wctype.h>

enum TokenType {
  IMPLICIT_TIMES,
};

struct NamedLetter {
  const int32_t *name;
  const int32_t unicode;
};

const size_t NUM_NAMED_LETTERS = 37;
const struct NamedLetter NAMED_LETTERS[37] = {
    {L"Plus", L'+'},
    {L"Minus", L'-'},
    {L"PlusMinus", L'\u00b1'},
    {L"MinusPlus", L'\u2213'},
    {L"Square", L'\u2213'},
    {L"Del", L'\u2207'},
    {L"DifferentialD", L'\uF75C'},
    {L"Not", L'\u00AC'},
    {L"Sqrt", L'\u221A'},
    {L"Cross", L'\uF4A0'},
    {L"SmallCircle", L'\u2218'},
    {L"Backslash", L'\u2216'},
    {L"Diamond", L'\u22C4'},
    {L"Wedge", L'\u22C0'},
    {L"Vee", L'\u22C1'},
    {L"CircleTimes", L'\u2297'},
    {L"CircleDot", L'\u2299'},
    {L"Star", L'\u22C6'},
    {L"VerticalTilde", L'\u2240'},
    {L"Coproduct", L'\u2210'},
    {L"Cap", L'\u2322'},
    {L"Cup", L'\u2323'},
    {L"CirclePlus", L'\u2295'},
    {L"CircleMinus", L'\u2296'},
    {L"Rule", L'\uF522'},
    {L"RuleDelayed", L'\uF51F'},
    {L"TwoWayRule", L'\uF120'},
    {L"Therefore", L'\u2234'},
    {L"RightTee", L'\u22A2'},
    {L"DoubleRightTee", L'\u22A8'},
    {L"SuchThat", L'\u220D'},
    {L"LeftTee", L'\u22A3'},
    {L"DoubleLeftTee", L'\u2AE4'},
    {L"UpTee", L'\u22A5'},
    {L"DownTee", L'\u22A4'},
    {L"Because", L'\u2235'},
    {L"Application", L'\u2235'},
};

static const int32_t RAWBACKSLASH = '\\';
static const int32_t LBRACKET = '[';
static const int32_t RBRACKET = ']';
static const int32_t LPAREN = '(';
static const int32_t RPAREN = ')';
static const int32_t ASTERISK = '*';
static const int32_t SLOT = '#';
static const int32_t BLANK = '_';
static const int32_t NOT = L'\u00AC';
static const int32_t SQUARE = L'\u2213';
static const int32_t DEL = L'\u2207';
static const int32_t DIFFERENTIALD = L'\uF75C';
static const int32_t SQRT = L'\u221A';
static const int32_t QUOTE = '"';

static bool is_newline(const int32_t c) {
  switch (c) {
  case '\n':
  case '\r':
  case '\f':
  case '\v':
  case L'\u2028':
  case L'\u2029':
    return true;
  default:
    return false;
  }
}

static bool is_whitespace(const int32_t c) {
  switch (c) {
  case ' ':
  case '\t':
  case L'\u2000':
  case L'\u2001':
  case L'\u2002':
  case L'\u2003':
  case L'\u2004':
  case L'\u2005':
  case L'\u2006':
  case L'\u2007':
  case L'\u2008':
  case L'\u2009':
  case L'\u200a':
  case L'\u200b':
  case L'\u202f':
  case L'\u205f':
  case L'\u3000':
  case L'\u00a0':
  case L'\u1680':
  case L'\u180e':
  case L'\ufeff':
    return true;
  default:
    return false;
  }
}
/**
 * Mark the end of the token.
 */
static void mark_end(TSLexer *lexer) { lexer->mark_end(lexer); }

/**
 * Advance lexer by one byte without skipping.
 */
static void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

/**
 * Return true if the lookahead is equal to the input.
 */
static bool is_next(const TSLexer *lexer, const int32_t c) {
  return lexer->lookahead == c;
}
/**
 * Return true if the lookahead is equal to whitespace.
 */
static bool is_next_whitespace(const TSLexer *lexer) {
  return is_whitespace(lexer->lookahead);
}
/**
 * Return true if the lookahead is equal to a newline.
 */
static bool is_next_newline(const TSLexer *lexer) {
  return is_newline(lexer->lookahead);
}

/**
 * Return true if the lookahead is alpha-numeric.
 */
static bool is_next_alnum(const TSLexer *lexer) {
  return iswalnum(lexer->lookahead);
}
/**
 * Return true if the lookahead is alpha-numeric.
 */
static bool is_next_alpha(const TSLexer *lexer) {
  return iswalpha(lexer->lookahead);
}
/**
 * Return true if the lookahead is alpha-numeric.
 */
static bool is_next_eof(const TSLexer *lexer) {
  return lexer->eof(lexer) || lexer->lookahead == '\0' ||
         lexer->lookahead == WEOF;
}

/**
 * If lookahead equals the character, then advance and return true. Otherwise,
 * don't advance and return false;
 */
static bool is_next_then_advance(TSLexer *lexer, const int32_t c) {
  if (is_next(lexer, c)) {
    advance(lexer);
    return true;
  }
  return false;
}

/**
 * Advance lexer by one byte and treat byte as whitespace.
 */
static void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

/**
 * Continue advancing lexer while whitespace and register the whitespace.
 */
static void advance_while_whitespace(TSLexer *lexer) {
  while (is_whitespace(lexer->lookahead)) {
    advance(lexer);
  }
}
/**
 * Continue advancing lexer while whitespace and register the whitespace.
 */
static void skip_while_whitespace(TSLexer *lexer) {
  while (is_whitespace(lexer->lookahead)) {
    skip(lexer);
  }
}

/**
 * Check if the named-letter is valid after whitespace for implicit
 * multiplication.
 */
static bool is_valid_ws_post_word(const int32_t *word) {
  if (wcscmp(word, L"Not") == 0 || wcscmp(word, L"Square") == 0 ||
      wcscmp(word, L"Del") == 0 || wcscmp(word, L"DifferentialD") == 0 ||
      wcscmp(word, L"Sqrt") == 0) {
    return true;
  }
  for (size_t i = 0; i < NUM_NAMED_LETTERS; ++i) {
    if (wcscmp(word, NAMED_LETTERS[i].name)) {
      return false;
    }
  }
  return true;
}

static bool is_next_valid_post_ws_char(TSLexer *lexer) {
  switch (lexer->lookahead) {
  case SLOT:
  case BLANK:
  case NOT:
  case SQUARE:
  case DEL:
  case DIFFERENTIALD:
  case SQRT:
    return true;
  }
  if (iswalnum(lexer->lookahead)) {
    return true;
  }
  return false;
}

bool scan_implicit_times(TSLexer *lexer) {

  if (is_next_alnum(lexer)) {
    return true;
  }

  if (is_next_then_advance(lexer, RAWBACKSLASH)) {
    advance_while_whitespace(lexer);
    // Line continuation: treat as whitespace and start over
    if (is_next_newline(lexer)) {
      advance(lexer);
      advance_while_whitespace(lexer);
      mark_end(lexer);
      return scan_implicit_times(lexer);
    }
    // Named letter \[...]
    if (is_next_then_advance(lexer, '[')) {
      // Parse word
      int32_t *word = malloc(30 * sizeof(int32_t));
      int i = 0;
      while (is_next_alpha(lexer)) {
        word[i] = lexer->lookahead;
        advance(lexer);
        i++;
      }
      word[i] = '\0';
      bool okay = false;
      if (is_next(lexer, ']')) {
        okay = is_valid_ws_post_word(word);
      }
      free(word);
      return okay;
    }
  }
  return false;
}

bool scan(TSLexer *lexer, const bool *valid_symbols) {
  bool consumed_ws = false;
  while (is_whitespace(lexer->lookahead)) {
    consumed_ws = true;
    advance(lexer);
  }
  mark_end(lexer);

  if (valid_symbols[IMPLICIT_TIMES] && consumed_ws) {
    return scan_implicit_times(lexer);
  }
  return false;
}

void *tree_sitter_wolfram_external_scanner_create() { return NULL; }
void tree_sitter_wolfram_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_wolfram_external_scanner_serialize(void *payload,
                                                        char *buffer) {
  return 0;
}
void tree_sitter_wolfram_external_scanner_deserialize(void *payload,
                                                      const char *buffer,
                                                      unsigned length) {}
bool tree_sitter_wolfram_external_scanner_scan(void *payload, TSLexer *lexer,
                                               const bool *valid_symbols) {
  return scan(lexer, valid_symbols);
}
