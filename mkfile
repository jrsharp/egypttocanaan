</$objtype/mkfile
BIN=/$objtype/bin/games

TARG=egypt
OFILES=\
	egypt.$O

HFILES=e2c.h\

UPDATE=\
	mkfile\
	$HFILES\
	${OFILES:%.$O=%.c}\
	`{ls /sys/games/lib/egypt/*}

</sys/src/cmd/mkone
