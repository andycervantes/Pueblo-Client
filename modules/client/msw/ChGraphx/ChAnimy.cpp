/*----------------------------------------------------------------------------
                        _                              _ _       
        /\             | |                            | (_)      
       /  \   _ __   __| |_ __ ___  _ __ ___   ___  __| |_  __ _ 
      / /\ \ | '_ \ / _` | '__/ _ \| '_ ` _ \ / _ \/ _` | |/ _` |
     / ____ \| | | | (_| | | | (_) | | | | | |  __/ (_| | | (_| |
    /_/    \_\_| |_|\__,_|_|  \___/|_| |_| |_|\___|\__,_|_|\__,_|

    The contents of this file are subject to the Andromedia Public
	License Version 1.0 (the "License"); you may not use this file
	except in compliance with the License. You may obtain a copy of
	the License at http://www.andromedia.com/APL/

    Software distributed under the License is distributed on an
	"AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
	implied. See the License for the specific language governing
	rights and limitations under the License.

    The Original Code is Pueblo client code, released November 4, 1998.

    The Initial Developer of the Original Code is Andromedia Incorporated.
	Portions created by Andromedia are Copyright (C) 1998 Andromedia
	Incorporated.  All Rights Reserved.

	Andromedia Incorporated                         415.365.6700
	818 Mission Street - 2nd Floor                  415.365.6701 fax
	San Francisco, CA 94103

    Contributor(s):
	--------------------------------------------------------------------------
	   Chaco team:  Dan Greening, Glenn Crocker, Jim Doubek,
	                Coyote Lussier, Pritham Shetty.

					Wrote and designed original codebase.

------------------------------------------------------------------------------

	Animation parser.

----------------------------------------------------------------------------*/

#include "grheader.h"
#include "ChAnim.h"
#include "ChGrMod.h"
#include "ChAniPrs.h"
#pragma warning( disable: 4068 )

/* redefine these values so they don't globally conflict -
   This is necessary for yacc. Can change when we go to bison.
 */

#define yyparse  	ChAnimParser::yyparse
#define yycvtok		ChAnimParser::yycvtok

// end of predefinitions
// ==================================================================
# define ANCHOR 257
# define ANCHORLIST 258
# define BACKGROUND 259
# define CAST 260
# define CASTID 261
# define CMDARG 262
# define COLUMNS 263
# define CURSOR 264
# define FALSEVAL 265
# define FILE 266
# define FLOAT 267
# define FORMAT 268
# define FRAMERATE 269
# define FRAMES 270
# define FRAMEVAL 271
# define GOTO 272
# define HINT 273
# define HOTCAST 274
# define HOTRECT 275
# define INT 276
# define ISANIMATING 277
# define ISDRAGGABLE 278
# define ISVISIBLE 279
# define MAZE 280
# define NAME 281
# define NODEID 282
# define ROWS 283
# define SCENE 284
# define SCRIPT 285
# define SCRIPTREF 286
# define SPRITE 287
# define STARTFRAME 288
# define STOP 289
# define STRING 290
# define TRUEVAL 291

#ifdef __STDC__
#include <stdlib.h>
#include <string.h>
#else
#include <malloc.h>
#include <memory.h>
#endif

#include <values.h>

#ifdef __cplusplus

#ifndef yyerror
	void yyerror(const char *);
#endif

#ifndef yylex
#ifdef __EXTERN_C__
	extern "C" { int yylex(void); }
#else
	int yylex(void);
#endif
#endif
	int yyparse(void);

#endif
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval;
YYSTYPE yyval;
typedef int yytabelem;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#if YYMAXDEPTH > 0
int yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
#else	/* user does initial allocation */
int *yys;
YYSTYPE *yyv;
#endif
static int yymaxdepth = YYMAXDEPTH;
# define YYERRCODE 256
yytabelem yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
	};
# define YYNPROD 85
# define YYLAST 208
yytabelem yyact[]={

   112,    90,    87,    62,    88,   126,   118,    13,    55,   117,
    65,   116,   111,    86,    89,    85,    37,    38,    36,   108,
    34,    33,    84,   106,     9,    58,    35,   136,    91,    61,
    46,    48,   135,     7,   122,     8,   107,   100,   134,   133,
    73,   132,    34,    33,   131,   130,   129,   128,   125,    47,
    73,    49,   124,   121,   120,    34,    33,    99,   119,     6,
     9,   115,   114,    68,    67,    57,   109,     7,    20,     8,
    52,    23,    69,    59,    54,    51,    12,    11,    10,   102,
    71,    40,    25,    27,    26,    72,    93,    60,    22,    16,
    29,     5,    18,     4,    17,     3,    75,    42,    41,   105,
   104,   103,   101,    45,    44,    50,    43,    56,    39,    98,
    53,    97,    92,    32,    31,    30,    28,    24,    70,    83,
    82,    66,    81,    42,    41,    63,    64,    80,    79,    78,
    77,    76,    74,    21,    19,    15,    90,    87,     2,    88,
     1,     0,     0,    95,    94,    96,     0,     0,    86,    89,
    85,   110,   108,     0,    46,    48,   106,    84,     0,     0,
    37,    38,    36,    91,    34,    33,    34,    33,     9,   107,
    35,   113,   100,    47,    14,    73,    95,    94,    96,   123,
     0,   127,     0,     0,     7,    20,     8,     0,     0,     0,
    34,    33,    99,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    23,     0,     0,     0,     0,    73 };
yytabelem yypact[]={

  -225,-10000000,-10000000,-10000000,-10000000,-10000000,   -45,   -46,   -47,  -116,
  -191,  -186,  -261,  -239,-10000000,   -74,-10000000,-10000000,-10000000,-10000000,
   -48,   -55,-10000000,   -49,  -117,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,  -211,  -265,   -50,  -262,  -262,  -262,  -115,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,  -212,  -213,   -51,-10000000,
-10000000,  -216,-10000000,-10000000,  -260,-10000000,-10000000,-10000000,-10000000,  -226,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,  -253,
   -59,-10000000,-10000000,  -278,  -125,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,  -214,  -215,  -279,  -281,  -284,  -218,
  -222,  -223,   -91,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,  -224,
  -228,  -120,-10000000,-10000000,-10000000,-10000000,  -229,-10000000,  -230,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,  -231,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,  -232,-10000000,
  -235,  -237,  -238,  -244,-10000000,  -249,-10000000 };
yytabelem yypgo[]={

     0,   140,   138,    94,    92,    90,   135,    89,   134,   133,
    88,   132,    96,   131,   130,   129,   128,   127,   122,   120,
   119,   118,    80,    85,   117,    82,    84,    83,   116,   115,
   114,   113,    87,   112,    86,   111,   109,   108,    81,   106,
   104,   103,   102,    79,   101,   100,    99 };
yytabelem yyr1[]={

     0,     1,     1,     1,     1,     2,     6,     6,     7,     7,
     7,     3,     9,     9,    10,    11,    11,    12,    12,    12,
    12,    12,    12,    12,    12,    13,    14,    15,    16,    17,
    18,    19,    20,     8,    21,    21,    22,     4,    24,    24,
    25,    25,    25,    25,    25,    25,    25,    26,    27,    29,
    30,    31,    32,    32,    28,    33,    33,    34,    34,    34,
    34,    34,    23,    35,    36,     5,     5,    37,    37,    38,
    38,    38,    38,    38,    39,    40,    41,    42,    42,    43,
    43,    43,    44,    45,    46 };
yytabelem yyr2[]={

     0,     3,     3,     3,     3,     9,     4,     3,     2,     2,
     2,     9,     4,     2,     9,     5,     3,     2,     2,     2,
     2,     2,     2,     2,     2,     5,    11,     5,     5,     5,
     5,     5,     5,     9,     5,     3,     2,     9,     5,     3,
     2,     2,     2,     2,     2,     2,     2,     5,     5,     5,
     5,     5,     3,     3,     9,     5,     3,     2,     2,     2,
     2,     2,     5,     5,     5,     9,     5,     5,     3,     2,
     2,     2,     2,     2,     5,     5,     9,     5,     3,     2,
     2,     2,    13,     3,     5 };
yytabelem yychk[]={

-10000000,    -1,    -2,    -3,    -4,    -5,   284,   258,   260,   285,
   123,   123,   123,   123,   290,    -6,    -7,    -3,    -4,    -8,
   259,    -9,   -10,   257,   -24,   -25,   -26,   -27,   -28,    -5,
   -29,   -30,   -31,   282,   281,   287,   279,   277,   278,   -37,
   -38,   -26,   -27,   -39,   -40,   -41,   269,   288,   270,   125,
    -7,   123,   125,   -10,   123,   125,   -25,   276,   290,   123,
   -32,   291,   265,   -32,   -32,   125,   -38,   276,   276,   123,
   -21,   -22,   -23,   266,   -11,   -12,   -13,   -14,   -15,   -16,
   -17,   -18,   -19,   -20,   282,   275,   273,   262,   264,   274,
   261,   288,   -33,   -34,   -26,   -27,   -23,   -35,   -36,   283,
   263,   -42,   -43,   -44,   -45,   -46,   276,   289,   272,   125,
   -22,   290,   125,   -12,   276,   276,   290,   290,   290,   276,
   276,   276,   125,   -34,   276,   276,   125,   -43,   276,   276,
   276,   276,   276,   276,   276,   276,   276 };
yytabelem yydef[]={

     0,    -2,     1,     2,     3,     4,     0,     0,     0,     0,
     0,     0,     0,     0,    66,     0,     7,     8,     9,    10,
     0,     0,    13,     0,     0,    39,    40,    41,    42,    43,
    44,    45,    46,     0,     0,     0,     0,     0,     0,     0,
    68,    69,    70,    71,    72,    73,     0,     0,     0,     5,
     6,     0,    11,    12,     0,    37,    38,    47,    48,     0,
    49,    52,    53,    50,    51,    65,    67,    74,    75,     0,
     0,    35,    36,     0,     0,    16,    17,    18,    19,    20,
    21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    56,    57,    58,    59,    60,    61,     0,
     0,     0,    78,    79,    80,    81,     0,    83,     0,    33,
    34,    62,    14,    15,    25,     0,    27,    28,    29,    30,
    31,    32,    54,    55,    63,    64,    76,    77,     0,    84,
     0,     0,     0,     0,    26,     0,    82 };
typedef struct
#ifdef __cplusplus
	yytoktype
#endif
{ char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	0	/* don't allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"ANCHOR",	257,
	"ANCHORLIST",	258,
	"BACKGROUND",	259,
	"CAST",	260,
	"CASTID",	261,
	"CMDARG",	262,
	"COLUMNS",	263,
	"CURSOR",	264,
	"FALSEVAL",	265,
	"FILE",	266,
	"FLOAT",	267,
	"FORMAT",	268,
	"FRAMERATE",	269,
	"FRAMES",	270,
	"FRAMEVAL",	271,
	"GOTO",	272,
	"HINT",	273,
	"HOTCAST",	274,
	"HOTRECT",	275,
	"INT",	276,
	"ISANIMATING",	277,
	"ISDRAGGABLE",	278,
	"ISVISIBLE",	279,
	"MAZE",	280,
	"NAME",	281,
	"NODEID",	282,
	"ROWS",	283,
	"SCENE",	284,
	"SCRIPT",	285,
	"SCRIPTREF",	286,
	"SPRITE",	287,
	"STARTFRAME",	288,
	"STOP",	289,
	"STRING",	290,
	"TRUEVAL",	291,
	"-unknown-",	-1	/* ends search */
};

char * yyreds[] =
{
	"-no such reduction-",
	"GraphicsFile : Scene",
	"GraphicsFile : AnchorListNode",
	"GraphicsFile : CastMember",
	"GraphicsFile : CastScript",
	"Scene : SCENE '{' SceneList '}'",
	"SceneList : SceneList SceneNode",
	"SceneList : SceneNode",
	"SceneNode : AnchorListNode",
	"SceneNode : CastMember",
	"SceneNode : Background",
	"AnchorListNode : ANCHORLIST '{' Anchors '}'",
	"Anchors : Anchors Anchor",
	"Anchors : Anchor",
	"Anchor : ANCHOR '{' AnchorDecls '}'",
	"AnchorDecls : AnchorDecls AnchorDecl",
	"AnchorDecls : AnchorDecl",
	"AnchorDecl : AnchorIdentifier",
	"AnchorDecl : AnchorRect",
	"AnchorDecl : AnchorHint",
	"AnchorDecl : AnchorCmdArg",
	"AnchorDecl : AnchorCursor",
	"AnchorDecl : AnchorHotCast",
	"AnchorDecl : AnchorCast",
	"AnchorDecl : AnchorStartFrame",
	"AnchorIdentifier : NODEID INT",
	"AnchorRect : HOTRECT INT INT INT INT",
	"AnchorHint : HINT STRING",
	"AnchorCmdArg : CMDARG STRING",
	"AnchorCursor : CURSOR STRING",
	"AnchorHotCast : HOTCAST INT",
	"AnchorCast : CASTID INT",
	"AnchorStartFrame : STARTFRAME INT",
	"Background : BACKGROUND '{' BackgroundDecls '}'",
	"BackgroundDecls : BackgroundDecls BackgroundDecl",
	"BackgroundDecls : BackgroundDecl",
	"BackgroundDecl : FileSpec",
	"CastMember : CAST '{' CastDecls '}'",
	"CastDecls : CastDecls CastDecl",
	"CastDecls : CastDecl",
	"CastDecl : NodeId",
	"CastDecl : NodeName",
	"CastDecl : Sprite",
	"CastDecl : CastScript",
	"CastDecl : IsVisible",
	"CastDecl : IsAnimating",
	"CastDecl : IsDraggable",
	"NodeId : NODEID INT",
	"NodeName : NAME STRING",
	"IsVisible : ISVISIBLE BoolValue",
	"IsAnimating : ISANIMATING BoolValue",
	"IsDraggable : ISDRAGGABLE BoolValue",
	"BoolValue : TRUEVAL",
	"BoolValue : FALSEVAL",
	"Sprite : SPRITE '{' SpriteDecls '}'",
	"SpriteDecls : SpriteDecls SpriteDecl",
	"SpriteDecls : SpriteDecl",
	"SpriteDecl : NodeId",
	"SpriteDecl : NodeName",
	"SpriteDecl : FileSpec",
	"SpriteDecl : Rows",
	"SpriteDecl : Columns",
	"FileSpec : FILE STRING",
	"Rows : ROWS INT",
	"Columns : COLUMNS INT",
	"CastScript : SCRIPT '{' ScriptDecls '}'",
	"CastScript : SCRIPT STRING",
	"ScriptDecls : ScriptDecls ScriptDecl",
	"ScriptDecls : ScriptDecl",
	"ScriptDecl : NodeId",
	"ScriptDecl : NodeName",
	"ScriptDecl : FrameRate",
	"ScriptDecl : StartFrame",
	"ScriptDecl : Frames",
	"FrameRate : FRAMERATE INT",
	"StartFrame : STARTFRAME INT",
	"Frames : FRAMES '{' FrameDecls '}'",
	"FrameDecls : FrameDecls FrameDecl",
	"FrameDecls : FrameDecl",
	"FrameDecl : FrameVal",
	"FrameDecl : FrameStop",
	"FrameDecl : FrameGoto",
	"FrameVal : INT INT INT INT INT INT",
	"FrameStop : STOP",
	"FrameGoto : GOTO INT",
};
#endif /* YYDEBUG */
/*
 * Copyright (c) 1993 by Sun Microsystems, Inc.
 */

#pragma ident	"@(#)yaccpar	6.12	93/06/07 SMI"

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
	(type *) memcpy(to, (char *) from, yynewmax * sizeof(type))
#define YYENLARGE( from, type) \
	(type *) realloc((char *) from, yynewmax * sizeof(type))
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-10000000)

/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */



#ifdef YYNMBCHARS
#define YYLEX()		yycvtok(yylex())
/*
** yycvtok - return a token if i is a wchar_t value that exceeds 255.
**	If i<255, i itself is the token.  If i>255 but the neither 
**	of the 30th or 31st bit is on, i is already a token.
*/
#if defined(__STDC__) || defined(__cplusplus)
int yycvtok(int i)
#else
int yycvtok(i) int i;
#endif
{
	int first = 0;
	int last = YYNMBCHARS - 1;
	int mid;
	wchar_t j;

	if(i&0x60000000){/*Must convert to a token. */
		if( yymbchars[last].character < i ){
			return i;/*Giving up*/
		}
		while ((last>=first)&&(first>=0)) {/*Binary search loop*/
			mid = (first+last)/2;
			j = yymbchars[mid].character;
			if( j==i ){/*Found*/ 
				return yymbchars[mid].tvalue;
			}else if( j<i ){
				first = mid + 1;
			}else{
				last = mid -1;
			}
		}
		/*No entry in the table.*/
		return i;/* Giving up.*/
	}else{/* i is already a token. */
		return i;
	}
}
#else/*!YYNMBCHARS*/
#define YYLEX()		yylex()
#endif/*!YYNMBCHARS*/

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
#if defined(__STDC__) || defined(__cplusplus)
int yyparse(void)
#else
int yyparse()
#endif
{
	register YYSTYPE *yypvt;	/* top of value stack for $vars */

#if defined(__cplusplus) || defined(lint)
/*
	hacks to please C++ and lint - goto's inside switch should never be
	executed; yypvt is set to 0 to avoid "used before set" warning.
*/
	static int __yaccpar_lint_hack__ = 0;
	switch (__yaccpar_lint_hack__)
	{
		case 1: goto yyerrlab;
		case 2: goto yynewstate;
	}
	yypvt = 0;
#endif

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

#if YYMAXDEPTH <= 0
	if (yymaxdepth <= 0)
	{
		if ((yymaxdepth = YYEXPAND(0)) <= 0)
		{
			yyerror("yacc initialization error");
			YYABORT;
		}
	}
#endif

	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			int yyps_index = (yy_ps - yys);
			int yypv_index = (yy_pv - yyv);
			int yypvt_index = (yypvt - yyv);
			int yynewmax;
#ifdef YYEXPAND
			yynewmax = YYEXPAND(yymaxdepth);
#else
			yynewmax = 2 * yymaxdepth;	/* double table size */
			if (yymaxdepth == YYMAXDEPTH)	/* first time growth */
			{
				char *newyys = (char *)YYNEW(int);
				char *newyyv = (char *)YYNEW(YYSTYPE);
				if (newyys != 0 && newyyv != 0)
				{
					yys = YYCOPY(newyys, yys, int);
					yyv = YYCOPY(newyyv, yyv, YYSTYPE);
				}
				else
					yynewmax = 0;	/* failed */
			}
			else				/* not first time */
			{
				yys = YYENLARGE(yys, int);
				yyv = YYENLARGE(yyv, YYSTYPE);
				if (yys == 0 || yyv == 0)
					yynewmax = 0;	/* failed */
			}
#endif
			if (yynewmax <= yymaxdepth)	/* tables not expanded */
			{
				yyerror( "yacc stack overflow" );
				YYABORT;
			}
			yymaxdepth = yynewmax;

			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			printf( "Received token " );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				printf( "Received token " );
				if ( yychar == 0 )
					printf( "end-of-file\n" );
				else if ( yychar < 0 )
					printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
			skip_init:
				yynerrs++;
				/* FALLTHRU */
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					printf( "Error recovery discards " );
					if ( yychar == 0 )
						printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{
		
case 1:
# line 95 "ChAnimy.y"
{m_lResult = yypvt[-0];} break;
case 2:
# line 97 "ChAnimy.y"
{m_lResult = yypvt[-0];} break;
case 3:
# line 99 "ChAnimy.y"
{m_lResult = yypvt[-0];} break;
case 4:
# line 101 "ChAnimy.y"
{m_lResult = yypvt[-0];} break;
case 5:
# line 104 "ChAnimy.y"
{ yyval = yypvt[-1];} break;
case 7:
# line 108 "ChAnimy.y"
{ yyval = yypvt[-0]; } break;
case 11:
# line 113 "ChAnimy.y"
{ yyval = 0; } break;
case 14:
# line 118 "ChAnimy.y"
{ yyval = AddAnchor( (ChBindList *)(yypvt[-1]) ); } break;
case 15:
# line 121 "ChAnimy.y"
{ yyval = AppendBindingList( (ChBindList *)(yypvt[-1]), (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 16:
# line 123 "ChAnimy.y"
{ yyval = NewBindingList( (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 25:
# line 136 "ChAnimy.y"
{ yyval = bind(NODEID, yypvt[-0]); } break;
case 26:
# line 139 "ChAnimy.y"
{ yyval = bind(HOTRECT, new CRect(yypvt[-3], yypvt[-2], yypvt[-1], yypvt[-0])); } break;
case 27:
# line 142 "ChAnimy.y"
{ yyval = bind(HINT, (void *)(yypvt[-0])); } break;
case 28:
# line 145 "ChAnimy.y"
{ yyval = bind(CMDARG, (void *)(yypvt[-0])); } break;
case 29:
# line 148 "ChAnimy.y"
{ yyval = bind(CURSOR, (void *)(yypvt[-0])); } break;
case 30:
# line 151 "ChAnimy.y"
{ yyval = bind(HOTCAST, yypvt[-0]); } break;
case 31:
# line 154 "ChAnimy.y"
{ yyval = bind(CAST, yypvt[-0]); } break;
case 32:
# line 157 "ChAnimy.y"
{ yyval = bind(STARTFRAME, yypvt[-0]); } break;
case 33:
# line 161 "ChAnimy.y"
{ 
		yyval = 0;
		Background( (ChBindList *)(yypvt[-1]) );
	} break;
case 34:
# line 167 "ChAnimy.y"
{ yyval = AppendBindingList( (ChBindList *)(yypvt[-1]), (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 35:
# line 169 "ChAnimy.y"
{ yyval = NewBindingList( (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 37:
# line 176 "ChAnimy.y"
{ 
		yyval = 0;
		AddCast( (ChBindList *)(yypvt[-1]) );
	} break;
case 38:
# line 182 "ChAnimy.y"
{ yyval = AppendBindingList( (ChBindList *)(yypvt[-1]), (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 39:
# line 184 "ChAnimy.y"
{ yyval = NewBindingList( (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 47:
# line 196 "ChAnimy.y"
{ yyval = bind(NODEID, yypvt[-0]); } break;
case 48:
# line 199 "ChAnimy.y"
{ yyval = bind(NAME, (void *)(yypvt[-0])); } break;
case 49:
# line 202 "ChAnimy.y"
{ yyval = bind(ISVISIBLE, (yypvt[-0])); } break;
case 50:
# line 205 "ChAnimy.y"
{ yyval = bind(ISANIMATING, (yypvt[-0])); } break;
case 51:
# line 208 "ChAnimy.y"
{ yyval = bind(ISDRAGGABLE, (yypvt[-0])); } break;
case 52:
# line 211 "ChAnimy.y"
{ yyval = 1; } break;
case 53:
# line 213 "ChAnimy.y"
{ yyval = 0; } break;
case 54:
# line 216 "ChAnimy.y"
{ 
		ChAnimParser * parser = ChAnimParser::GetParser();
		yyval = parser->bind(SPRITE, (void *)(parser->Sprite( (ChBindList *)(yypvt[-1]) )));
	} break;
case 55:
# line 222 "ChAnimy.y"
{ yyval = AppendBindingList( (ChBindList *)(yypvt[-1]), (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 56:
# line 224 "ChAnimy.y"
{ yyval = NewBindingList( (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 62:
# line 233 "ChAnimy.y"
{ yyval = bind(FILE, (void *)(yypvt[-0])); } break;
case 63:
# line 236 "ChAnimy.y"
{ yyval = bind(ROWS, yypvt[-0]); } break;
case 64:
# line 239 "ChAnimy.y"
{ yyval = bind(COLUMNS, yypvt[-0]); } break;
case 65:
# line 243 "ChAnimy.y"
{ 
		yyval = bind(SCRIPT, (void *)(Script((ChBindList *)(yypvt[-1]))));
	} break;
case 66:
# line 247 "ChAnimy.y"
{
		yyval = bind(SCRIPTREF, (void *)(yypvt[-0]));
	} break;
case 67:
# line 252 "ChAnimy.y"
{ yyval = AppendBindingList( (ChBindList *)(yypvt[-1]), (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 68:
# line 254 "ChAnimy.y"
{ yyval = NewBindingList( (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 74:
# line 263 "ChAnimy.y"
{ yyval = bind(FRAMERATE, yypvt[-0]); } break;
case 75:
# line 266 "ChAnimy.y"
{ yyval = bind(STARTFRAME, yypvt[-0]); } break;
case 76:
# line 269 "ChAnimy.y"
{ 
		ChAnimParser * parser = ChAnimParser::GetParser();
		yyval = parser->bind(FRAMES, parser->Frames( (ChBindList *)(yypvt[-1]) ));
	} break;
case 77:
# line 275 "ChAnimy.y"
{ yyval = AppendBindingList( (ChBindList *)(yypvt[-1]), (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 78:
# line 277 "ChAnimy.y"
{ yyval = NewBindingList( (ChAnimBindVal*)(yypvt[-0]) ); } break;
case 82:
# line 285 "ChAnimy.y"
{ yyval = bind(FRAMEVAL, new ChCell(yypvt[-5], yypvt[-4], yypvt[-3], yypvt[-2], yypvt[-1], yypvt[-0])); } break;
case 83:
# line 288 "ChAnimy.y"
{ yyval = bind(STOP, 0); } break;
case 84:
# line 291 "ChAnimy.y"
{ yyval = bind(GOTO, yypvt[-0]); } break;
	}
	goto yystack;		/* reset registers in driver code */
}

