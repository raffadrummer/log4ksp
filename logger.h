/*
	Copyright 2014 Raffaella Migliaccio

	This file is part of log4ksp.

    Log4ksp is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    Log4ksp is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
    details.

    You should have received a copy of the GNU Lesser General Public License
    along with Log4ksp.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NDEBUG

declare $_logger_idx_

#ifdef VERBOSE_LOGGING
#define LOG( MSG ) pgs_set_str_key_val( LOG_MESSAGE, __FILE__ & ":" & __LINE__ & ": " & MSG )
#else
#define LOG( MSG ) pgs_set_str_key_val( LOG_MESSAGE, MSG ) @@@ wait( 1 )
#endif

#define LOG_EXP( EXP ) LOG( #EXP & " => " & EXP )

#define LOG_ARR( ARR, LEN ) \
	LOG( #ARR & " => [ " ) @@@\
	$_logger_idx_ := 0 @@@\
	while ( $_logger_idx_ < ( LEN ) ) @@@\
		LOG( "    " & ARR[ $_logger_idx_ ] ) @@@\
		inc( $_logger_idx_ ) @@@\
	end while @@@\
	LOG( "]" )

#else

#define LOG( MSG )
#define LOG_EXP( EXP )
#define LOG_ARR( ARR, LEN )

#endif
