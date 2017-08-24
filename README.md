# md-html
Markdown to HTML converter; honors inline HTML.

## Usage
Usage: `md-html [FILE]`
This will convert markdown file [FILE] into HTML, preserving inline HTML in the process.
The converted file will then be sent to stdout, where it can be redirected to a file to be saved.

Example usage:
`md-html src/about.md > dist/about.html`

md-html is licensed under GPL-3.0. <https://www.gnu.org/licenses/gpl-3.0.en.html>  
md-html homepage: <http://git.mattconn.io/md-html.git/>

## Building
Run `make` to generate scanner with flex and compile with clang. Binary will be `bin/md-html`.  
Run `make check` to convert `test.md` to HTML and send the converted file to stdout.  
To use a different compiler and set flags, edit the appropriate lines in makefile.

## Syntax specifics
### Differences from standard markdown
md-html uses mostly standard markdown syntax, with a few exceptions listed below, ordered from greatest to least deviation from the standard:

### Disabling markdown syntax
Much like the backticks (\`\`\`) used for codeblocks in markdown, markdown syntax can be disabled for text written between two sets of three commas (`,,,`).  

### Ordered lists
Typically an ordered list is created by prefixing a list item with a number followed by a period; it can be any number, and the numbering can be out of order, or can even be repetitive. 
e.g.:
```
2. foo
4. bar
3. baz
```
Instead of this method, md-html uses the typical unordered list dash, but followed by a period:
```
-. foo
-. bar
-. baz
```

### p-tags
#### No two spaces for carriage returns
p-tags are written the standard way; just write on a new line without any extra markup. However, carriage returns are honored without the excess two spaces before the end of a line.


### h-tags
An h-tag (`h1`, `h2`, etc.) is denoted the usual way: by n amount of `#`'s before text.
e.g.: `##An h2`
While h-tags can also be written with an underline in markdown, like the following:
```
An h-tag
========
```
md-html does not honor this method.

# Features needed/wanted
md-html currently does not honor image or blockquote markdown, as well as autolinks or references, but it may in the future.
