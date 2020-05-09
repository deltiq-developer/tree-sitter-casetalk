module.exports = grammar({
  name: "CaseTalk",

  rules: {
    // Main structure
    program: $ => repeat(choice(
      $.comment,
      $.header,
      $.fact,
      $.tag,
    )),

    header: $ => token(seq('[',/.*/,']')),
    comment: $ => token(seq(';', /.*/)),
    fact: $ => token(seq (
      choice("'", '"'),
      /.*/,
      choice("'", '"')
    )),
    tag: $ => /Tag|tag/
  }
})
