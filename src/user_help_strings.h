char help_notice[] = {"Try \"md-html -h\" for usage/information."};

char help_message[] = "Usage: md-html [FILE]\n\
This will convert markdown file [FILE] into HTML, preserving inline HTML in the process.\n\
The converted file will then be sent to stdout, where it can be redirected to a file to be saved.\n\
\n\
Example usage:\n\
md-html src/about.md > dist/about.html\n\
\n\
md-html is licensed under GPL-3.0. <https://www.gnu.org/licenses/gpl-3.0.en.html>\n\
md-html homepage: <http://git.mattconn.io/md-html.git/>";
