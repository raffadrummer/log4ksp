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
