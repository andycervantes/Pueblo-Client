%{
/*----------------------------------------------------------------------------

            .###.  ###     ###       ,#,          .###.    ,#######,
         ,####""   ###    .###     ,##'##,     ,####""   .##'    `##.
        ###        ###########    ,##' `##,   ###       ####      ####
        ###..      ###'    ###  ,###########, ####..    `###,    ,##'
          `######  ###     ###  `##'     `##'   `######   `########'


	Copyright 1995, Chaco Communications, Inc. All rights reserved.
	Unpublished -- Rights reserved under the copyright laws of the United
	States.  Use of a copyright notice is precautionary only and does no
	imply publication or disclosure.

	This software contains confidential information and trade secrets of
	Chaco Communications, Inc.  Use, disclosure, or reproduction is
	prohibited without the prior express written permission of Chaco
	Communications, Inc.

	RESTRICTED RIGHTS LEGEND

	Use, duplication, or disclosure by the Government is subject to
	restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
	Technical Data and Computer Software clause at DFARS 252.227-7013.

	Chaco Communications, Inc.
	10164 Parkwood Drive, Suite 8, Cupertino, CA, 95014-1533

------------------------------------------------------------------------------

	Animation parser.

----------------------------------------------------------------------------*/

// $Header: /home/cvs/chaco/modules/client/msw/ChGraphx/ChAnimy.y,v 2.0 1995/05/11 00:12:21 coyote Exp $

#include "headers.h"
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
%}

%token	ANCHOR
%token	ANCHORLIST
%token	BACKGROUND
%token	CAST
%token	CASTID
%token	CMDARG
%token	COLUMNS 
%token	CURSOR
%token	FALSEVAL 
%token	FILE 
%token	FLOAT
%token	FORMAT 
%token	FRAMERATE 
%token	FRAMES
%token	FRAMEVAL
%token	GOTO
%token	HINT
%token	HOTCAST
%token	HOTRECT
%token	INT
%token	ISANIMATING 
%token	ISDRAGGABLE
%token	ISVISIBLE 
%token	MAZE
%token	NAME
%token	NODEID
%token	ROWS 
%token	SCENE
%token	SCRIPT 
%token	SCRIPTREF 
%token	SPRITE 
%token	STARTFRAME
%token	STOP 
%token	STRING
%token	TRUEVAL
 

%%

GraphicsFile : Scene
					{m_lResult = $1;} 
				| AnchorListNode 
					{m_lResult = $1;} 
				| CastMember 
					{m_lResult = $1;} 
				| CastScript
					{m_lResult = $1;} 

Scene : SCENE '{' SceneList '}'
	{ $$ = $3;}

SceneList : SceneList SceneNode
			| SceneNode
				{ $$ = $1; }

SceneNode : AnchorListNode | CastMember  | Background /* | Maze | CastScript  */

AnchorListNode : ANCHORLIST '{' Anchors '}'
	{ $$ = 0; }

Anchors : Anchors Anchor | Anchor

Anchor : ANCHOR '{' AnchorDecls '}'
	{ $$ = AddAnchor( (ChBindList *)($3) ); }

AnchorDecls : 	AnchorDecls AnchorDecl 
				{ $$ = AppendBindingList( (ChBindList *)($1), (ChAnimBindVal*)($2) ); }
				| AnchorDecl
				{ $$ = NewBindingList( (ChAnimBindVal*)($1) ); }

AnchorDecl : 
				AnchorIdentifier |
				AnchorRect |
				AnchorHint |
				AnchorCmdArg |
				AnchorCursor |
				AnchorHotCast |
				AnchorCast | 
				AnchorStartFrame /**/

AnchorIdentifier : NODEID INT	
	{ $$ = bind(NODEID, $2); }

AnchorRect : HOTRECT INT INT INT INT
	{ $$ = bind(HOTRECT, new CRect($2, $3, $4, $5)); }

AnchorHint : HINT STRING
	{ $$ = bind(HINT, (void *)($2)); }

AnchorCmdArg : CMDARG STRING 
	{ $$ = bind(CMDARG, (void *)($2)); }

AnchorCursor : CURSOR STRING 
	{ $$ = bind(CURSOR, (void *)($2)); }

AnchorHotCast : HOTCAST INT
	{ $$ = bind(HOTCAST, $2); }

AnchorCast : CASTID INT  
	{ $$ = bind(CAST, $2); }

AnchorStartFrame : STARTFRAME INT
	{ $$ = bind(STARTFRAME, $2); }

/* Background dib */
Background : BACKGROUND '{' BackgroundDecls '}'
	{ 
		$$ = 0;
		Background( (ChBindList *)($3) );
	}

BackgroundDecls	: BackgroundDecls  BackgroundDecl
				{ $$ = AppendBindingList( (ChBindList *)($1), (ChAnimBindVal*)($2) ); }
					| BackgroundDecl
				{ $$ = NewBindingList( (ChAnimBindVal*)($1) ); }

BackgroundDecl :  FileSpec

/* Cast member */

CastMember : CAST '{' CastDecls '}'
	{ 
		$$ = 0;
		AddCast( (ChBindList *)($3) );
	}

CastDecls :	CastDecls CastDecl 
				{ $$ = AppendBindingList( (ChBindList *)($1), (ChAnimBindVal*)($2) ); }
			| CastDecl
				{ $$ = NewBindingList( (ChAnimBindVal*)($1) ); }

CastDecl : 	NodeId
			| NodeName 
			| Sprite 
			| CastScript 
			/* |ScriptRef*/
			| IsVisible
			| IsAnimating
			| IsDraggable

NodeId : NODEID INT	
	{ $$ = bind(NODEID, $2); }

NodeName : NAME STRING
	{ $$ = bind(NAME, (void *)($2)); }

IsVisible 	:  ISVISIBLE BoolValue
	{ $$ = bind(ISVISIBLE, ($2)); }
  
IsAnimating	:  ISANIMATING  BoolValue
	{ $$ = bind(ISANIMATING, ($2)); }

IsDraggable	:  ISDRAGGABLE  BoolValue
	{ $$ = bind(ISDRAGGABLE, ($2)); }

BoolValue : TRUEVAL 
				{ $$ = 1; }
			| FALSEVAL
				{ $$ = 0; }

Sprite : SPRITE '{' SpriteDecls '}'
	{ 
		ChAnimParser * parser = ChAnimParser::GetParser();
		$$ = parser->bind(SPRITE, (void *)(parser->Sprite( (ChBindList *)($3) )));
	}

SpriteDecls	: 	SpriteDecls SpriteDecl 
				{ $$ = AppendBindingList( (ChBindList *)($1), (ChAnimBindVal*)($2) ); }
				| SpriteDecl		  
				{ $$ = NewBindingList( (ChAnimBindVal*)($1) ); }

SpriteDecl :  	NodeId 
				| NodeName 
				| FileSpec 
				| Rows 
				| Columns 

FileSpec : FILE STRING
	{ $$ = bind(FILE, (void *)($2)); }

Rows : ROWS INT
	{ $$ = bind(ROWS, $2); }

Columns : COLUMNS INT
	{ $$ = bind(COLUMNS, $2); }

/* Inline script - save for cast */
CastScript : SCRIPT '{' ScriptDecls '}'
	{ 
		$$ = bind(SCRIPT, (void *)(Script((ChBindList *)($3))));
	}
	| SCRIPT STRING
	{
		$$ = bind(SCRIPTREF, (void *)($2));
	}

ScriptDecls	: 	ScriptDecls ScriptDecl 
				{ $$ = AppendBindingList( (ChBindList *)($1), (ChAnimBindVal*)($2) ); }
				| ScriptDecl		  
				{ $$ = NewBindingList( (ChAnimBindVal*)($1) ); }
 
ScriptDecl : 	NodeId 
				| NodeName 
				| FrameRate
				| StartFrame
				| Frames

FrameRate :	FRAMERATE  INT
	{ $$ = bind(FRAMERATE, $2); }

StartFrame : STARTFRAME	INT
	{ $$ = bind(STARTFRAME, $2); }

Frames : FRAMES	'{' FrameDecls '}'
	{ 
		ChAnimParser * parser = ChAnimParser::GetParser();
		$$ = parser->bind(FRAMES, parser->Frames( (ChBindList *)($3) ));
	}

FrameDecls	: 	FrameDecls FrameDecl 
				{ $$ = AppendBindingList( (ChBindList *)($1), (ChAnimBindVal*)($2) ); }
				| FrameDecl		  
				{ $$ = NewBindingList( (ChAnimBindVal*)($1) ); }

FrameDecl :	FrameVal 
			| FrameStop
			| FrameGoto


FrameVal : INT INT INT INT INT INT
	{ $$ = bind(FRAMEVAL, new ChCell($1, $2, $3, $4, $5, $6)); }

FrameStop : STOP 
	{ $$ = bind(STOP, 0); }

FrameGoto : GOTO INT
	{ $$ = bind(GOTO, $2); }
