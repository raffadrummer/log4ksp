# Log 4 KSP

This repository contains a simple *logging system* for
"[Kontakt](http://www.native-instruments.com/en/products/komplete/samplers/kontakt-5/) Scripting Language"
scripts.

The purpose of a *logging system* is to enable the programmer to collect
diagnostic messages (typically used for debugging) produced during script
execution.

## Simple usage

To *log* a diagnostic message, is enough to insert a call as

	pgs_set_str_key_val( LOG_MESSAGE, "" )

putting the message text within the double quotes. To *collect* the messages one
must load the [logger.ksp](logger.ksp) script in one of the script tabs and use such tab to show (and possibly save) the collected messages.

As an example, you can load the file [simple.ksp](examples/simple.ksp) in one tab; then pressing the button will log the "HERE I AM" message in the `logger.ksp` script tab.

## Use with macros

As explained in [Macros 4 KSP](https://github.com/raffadrummer/macros4ksp) repository, it is possible to use the C preprocessor to both simplify and make more powerful the use of the logging system.

First you need to include the [logger.h](logger.h) *header file* in your KSP script, then you must "compile" it using the C preprocessor; in order to perform this you can use the [Makefile](Makefile).

The inclusion of the header file makes possible to use the following *macros*

	LOG( <message> )
	LOG_EXP( <expression> )
	LOG_ARR( <array>, <lenght> )

that allow to, respectively, log:

- a `<message>`,
- an `<expression>` (its name and value),
- an `<array>`, that is the content of its first `<length>` positions.

As an example, you can see the [with-macros.ksp](examples/with-macros.ksp) file (that contains an example for every one of the above macros).

To actually test the above example (assuming you are using a GNU/Linux system where the GNU `cpp` C preprocessor and `make` command have already been installed), you can perform the following steps

	cd examples
	ln -s ../Makefile .
	ln -s ../logger.h .
	make with-macros.txt

and then load the `with-macros.txt` file in one of the script tabs.


[![Analytics](https://ga-beacon.appspot.com/UA-49277456-5/log4ksp?pixel)](https://github.com/igrigorik/ga-beacon)
