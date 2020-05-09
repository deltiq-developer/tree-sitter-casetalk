// Compile: tree-sitter generate; node-gyp configure; node-gyp build; tree-sitter test;
// Publish: npm publish

module.exports = grammar({
  name: "CaseTalk",

  rules: {
    // Main structure
    program: $ => repeat(choice(
      $.comment,
      $.header,
      $.fact,
    )),

    header: $ => token(seq('[',/.*/,']')),
    comment: $ => token(seq(';', /.*/)),

    // Supporting elements:
    tag: $ => token(seq(',',/\s*/,/Tag|tag/)),
    quote: $ => choice("'", '"'),

    fact: $ => token(seq (
      $.quote,
      /.*/,
      $.quote,
      optional($.tag),
    )),

  }
})
