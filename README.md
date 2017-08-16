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

## Syntax specifics
md-html uses mostly standard markdown syntax, with a few exceptions listed below, determined mostly by my preferences:

### h-tags
An h-tag (`<h1>`, `<h2>`, etc.) is denoted the usual way: by n amount of `#`'s before text.
e.g.: `##An h2`
While h-tags can also be written with an underline in markdown, like the following:
```
An h-tag
========
```
md-html does not honor this method.

### p-tags
p-tags are written the standard way; just write on a new line without any extra markup. However, carriage returns are honored without the excess two spaces that are typically needed.

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
### code tags
You can write code in code tags (\'code here\') and code blocks normally:
```
\'\'\'
code here
\'\'\'
``` 
If writing HTML tags within code tags, the `<` and `>` will be generated as HTML entities.

# Features needed/wanted
md-html currently does not honor image or blockquote markdown, but it may in the future.
