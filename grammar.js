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
    fact: $ => token(seq (
      choice("'", '"'),
      /.*/,
      choice("'", '"'),
      optional(seq(
        /\s*/,
        ',',
        /\s*/,
        /(Tag|tag){1}/
      )),
    )),

  }
})
