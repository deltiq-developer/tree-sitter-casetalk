#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 7
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 8
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2

enum {
  sym_header = 1,
  sym_comment = 2,
  sym_content = 3,
  sym_tag = 4,
  sym_program = 5,
  sym_fact = 6,
  aux_sym_program_repeat1 = 7,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_header] = "header",
  [sym_comment] = "comment",
  [sym_content] = "content",
  [sym_tag] = "tag",
  [sym_program] = "program",
  [sym_fact] = "fact",
  [aux_sym_program_repeat1] = "program_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_header] = sym_header,
  [sym_comment] = sym_comment,
  [sym_content] = sym_content,
  [sym_tag] = sym_tag,
  [sym_program] = sym_program,
  [sym_fact] = sym_fact,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_header] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_content] = {
    .visible = true,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym_fact] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(8);
      if (lookahead == '"' ||
          lookahead == '\'') ADVANCE(7);
      if (lookahead == ',') ADVANCE(1);
      if (lookahead == ';') ADVANCE(10);
      if (lookahead == '[') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == 'T') ADVANCE(4);
      if (lookahead == 't') ADVANCE(4);
      END_STATE();
    case 3:
      if (lookahead == ']') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == 'g') ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == '"' ||
          lookahead == '\'') ADVANCE(11);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'') ADVANCE(6);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_header);
      if (lookahead == ']') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_content);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_tag);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_header] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_content] = ACTIONS(1),
    [sym_tag] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(6),
    [sym_fact] = STATE(2),
    [aux_sym_program_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_header] = ACTIONS(5),
    [sym_comment] = ACTIONS(5),
    [sym_content] = ACTIONS(7),
  },
  [2] = {
    [sym_fact] = STATE(3),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_header] = ACTIONS(11),
    [sym_comment] = ACTIONS(11),
    [sym_content] = ACTIONS(7),
  },
  [3] = {
    [sym_fact] = STATE(3),
    [aux_sym_program_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_header] = ACTIONS(15),
    [sym_comment] = ACTIONS(15),
    [sym_content] = ACTIONS(18),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym_header] = ACTIONS(21),
    [sym_comment] = ACTIONS(21),
    [sym_content] = ACTIONS(21),
    [sym_tag] = ACTIONS(23),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(25), 4,
      ts_builtin_sym_end,
      sym_header,
      sym_comment,
      sym_content,
  [7] = 1,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 7,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, REDUCE(sym_program, 0),
  [5] = {.count = 1, .reusable = true}, SHIFT(2),
  [7] = {.count = 1, .reusable = true}, SHIFT(4),
  [9] = {.count = 1, .reusable = true}, REDUCE(sym_program, 1),
  [11] = {.count = 1, .reusable = true}, SHIFT(3),
  [13] = {.count = 1, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2),
  [15] = {.count = 2, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(3),
  [18] = {.count = 2, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(4),
  [21] = {.count = 1, .reusable = true}, REDUCE(sym_fact, 1),
  [23] = {.count = 1, .reusable = true}, SHIFT(5),
  [25] = {.count = 1, .reusable = true}, REDUCE(sym_fact, 2),
  [27] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_CaseTalk(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
