log4ksp
=======

This repository contains a simple logging system for
"[Kontakt](http://www.native-
instruments.com/en/products/komplete/samplers/kontakt-5/) Scripting Language"
scripts.

The purpose of a logging system is to enable the programmer to collect
diagnostic messages (typically used for debugging) produced during script
execution.

To *log* a diagnostic message, is enough to insert a call as

	pgs_set_str_key_val( LOG_MESSAGE, "" )

putting the message within the double quotes. To *collect* the messages one
must load the `logger.ksp` script in one of the script tabs and use such tab
to show (and possibly save) the collected messages.
