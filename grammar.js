// Compile: tree-sitter generate; node-gyp configure; node-gyp build; tree-sitter test;
// Publish: npm publish

module.exports = grammar({
  name: "CaseTalk",

  rules: {
    // Main structure
    program: $ => repeat(choice(
      $.comment,
      $.header,
      $.fact
    )),

    extras: $ => [
      $.comment,
      /[\s\f\uFEFF\u2060\u200B]|\\\r?\n/
    ],

    header: $ => token(seq('[',/.*/,']')),
    comment: $ => token(seq(';', /.*/)),

    // Supporting elements:
    content: $ => token(seq(/\'|\"/,/[^\'\"]*/,/\'|\"/)),
    fact: $ => token(seq(
      $.content,
      optional($.tag)),
    )),

    tag: $ => token(/(\s)*(, ){1}(Tag|tag){1}/),

  }
})
