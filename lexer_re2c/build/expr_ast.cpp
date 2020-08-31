/* expr_ast.cpp.  Generated automatically by treecc */
#line 24 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"

    #include "expr_ast.h"

#line 7 "expr_ast.cpp"

#include <cstddef>

namespace Ast
{

#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	offsetof(_YYNODESTATE_align_##type, field)
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

const char *YYNODESTATE::currFilename() const
{
	return (const char *)0;
}

long YYNODESTATE::currLinenum() const
{
	return 0;
}

#endif
#line 291 "expr_ast.cpp"
void *AstNode::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void AstNode::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

AstNode::AstNode()
{
	this->kind__ = AstNode_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

AstNode::~AstNode()
{
	// not used
}

int AstNode::isA(int kind) const
{
	if(kind == AstNode_kind)
		return 1;
	else
		return 0;
}

const char *AstNode::getKindName() const
{
	return "AstNode";
}

Expr::Expr()
	: AstNode()
{
	this->kind__ = Expr_kind;
}

Expr::~Expr()
{
	// not used
}

int Expr::isA(int kind) const
{
	if(kind == Expr_kind)
		return 1;
	else
		return AstNode::isA(kind);
}

const char *Expr::getKindName() const
{
	return "Expr";
}

Stmt::Stmt()
	: AstNode()
{
	this->kind__ = Stmt_kind;
}

Stmt::~Stmt()
{
	// not used
}

int Stmt::isA(int kind) const
{
	if(kind == Stmt_kind)
		return 1;
	else
		return AstNode::isA(kind);
}

const char *Stmt::getKindName() const
{
	return "Stmt";
}

BinaryExpr::BinaryExpr(Expr * expr1, Expr * expr2)
	: Expr()
{
	this->kind__ = BinaryExpr_kind;
	this->expr1 = expr1;
	this->expr2 = expr2;
}

BinaryExpr::~BinaryExpr()
{
	// not used
}

int BinaryExpr::isA(int kind) const
{
	if(kind == BinaryExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *BinaryExpr::getKindName() const
{
	return "BinaryExpr";
}

NumExpr::NumExpr(int value)
	: Expr()
{
	this->kind__ = NumExpr_kind;
	this->value = value;
}

NumExpr::~NumExpr()
{
	// not used
}

int NumExpr::eval(SymbolTable & vars)
#line 95 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{
    return value;
}
#line 418 "expr_ast.cpp"

int NumExpr::isA(int kind) const
{
	if(kind == NumExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *NumExpr::getKindName() const
{
	return "NumExpr";
}

IdExpr::IdExpr(string_t id)
	: Expr()
{
	this->kind__ = IdExpr_kind;
	this->id = id;
}

IdExpr::~IdExpr()
{
	// not used
}

int IdExpr::eval(SymbolTable & vars)
#line 99 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{
    auto it = vars.find(id);

    if(it != vars.end())
        return it->second;
    else
        throw std::exception();
}
#line 455 "expr_ast.cpp"

int IdExpr::isA(int kind) const
{
	if(kind == IdExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *IdExpr::getKindName() const
{
	return "IdExpr";
}

AddExpr::AddExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = AddExpr_kind;
}

AddExpr::~AddExpr()
{
	// not used
}

int AddExpr::eval(SymbolTable & vars)
#line 84 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) + expr2->eval(vars);}
#line 484 "expr_ast.cpp"

int AddExpr::isA(int kind) const
{
	if(kind == AddExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *AddExpr::getKindName() const
{
	return "AddExpr";
}

SubExpr::SubExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = SubExpr_kind;
}

SubExpr::~SubExpr()
{
	// not used
}

int SubExpr::eval(SymbolTable & vars)
#line 85 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) - expr2->eval(vars);}
#line 513 "expr_ast.cpp"

int SubExpr::isA(int kind) const
{
	if(kind == SubExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *SubExpr::getKindName() const
{
	return "SubExpr";
}

MulExpr::MulExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = MulExpr_kind;
}

MulExpr::~MulExpr()
{
	// not used
}

int MulExpr::eval(SymbolTable & vars)
#line 86 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) * expr2->eval(vars);}
#line 542 "expr_ast.cpp"

int MulExpr::isA(int kind) const
{
	if(kind == MulExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MulExpr::getKindName() const
{
	return "MulExpr";
}

DivExpr::DivExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = DivExpr_kind;
}

DivExpr::~DivExpr()
{
	// not used
}

int DivExpr::eval(SymbolTable & vars)
#line 87 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) / expr2->eval(vars);}
#line 571 "expr_ast.cpp"

int DivExpr::isA(int kind) const
{
	if(kind == DivExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *DivExpr::getKindName() const
{
	return "DivExpr";
}

GTExpr::GTExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = GTExpr_kind;
}

GTExpr::~GTExpr()
{
	// not used
}

int GTExpr::eval(SymbolTable & vars)
#line 88 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) > expr2->eval(vars);}
#line 600 "expr_ast.cpp"

int GTExpr::isA(int kind) const
{
	if(kind == GTExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *GTExpr::getKindName() const
{
	return "GTExpr";
}

LTExpr::LTExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = LTExpr_kind;
}

LTExpr::~LTExpr()
{
	// not used
}

int LTExpr::eval(SymbolTable & vars)
#line 89 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) < expr2->eval(vars);}
#line 629 "expr_ast.cpp"

int LTExpr::isA(int kind) const
{
	if(kind == LTExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *LTExpr::getKindName() const
{
	return "LTExpr";
}

GEExpr::GEExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = GEExpr_kind;
}

GEExpr::~GEExpr()
{
	// not used
}

int GEExpr::eval(SymbolTable & vars)
#line 90 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) >= expr2->eval(vars);}
#line 658 "expr_ast.cpp"

int GEExpr::isA(int kind) const
{
	if(kind == GEExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *GEExpr::getKindName() const
{
	return "GEExpr";
}

LEExpr::LEExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = LEExpr_kind;
}

LEExpr::~LEExpr()
{
	// not used
}

int LEExpr::eval(SymbolTable & vars)
#line 91 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) <= expr2->eval(vars);}
#line 687 "expr_ast.cpp"

int LEExpr::isA(int kind) const
{
	if(kind == LEExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *LEExpr::getKindName() const
{
	return "LEExpr";
}

EqExpr::EqExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = EqExpr_kind;
}

EqExpr::~EqExpr()
{
	// not used
}

int EqExpr::eval(SymbolTable & vars)
#line 92 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) == expr2->eval(vars);}
#line 716 "expr_ast.cpp"

int EqExpr::isA(int kind) const
{
	if(kind == EqExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *EqExpr::getKindName() const
{
	return "EqExpr";
}

NotExpr::NotExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = NotExpr_kind;
}

NotExpr::~NotExpr()
{
	// not used
}

int NotExpr::eval(SymbolTable & vars)
#line 93 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{ return expr1->eval(vars) != expr2->eval(vars);}
#line 745 "expr_ast.cpp"

int NotExpr::isA(int kind) const
{
	if(kind == NotExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *NotExpr::getKindName() const
{
	return "NotExpr";
}

AssignStmt::AssignStmt(string_t id, Expr * expr)
	: Stmt()
{
	this->kind__ = AssignStmt_kind;
	this->id = id;
	this->expr = expr;
}

AssignStmt::~AssignStmt()
{
	// not used
}

int AssignStmt::eval(SymbolTable & vars)
#line 108 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{
    int value = expr->eval(vars);
    vars[id] = value;

    return 0;
}
#line 781 "expr_ast.cpp"

int AssignStmt::isA(int kind) const
{
	if(kind == AssignStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *AssignStmt::getKindName() const
{
	return "AssignStmt";
}

BlockStmt::BlockStmt(NodeVector l)
	: Stmt()
{
	this->kind__ = BlockStmt_kind;
	this->l = l;
}

BlockStmt::~BlockStmt()
{
	// not used
}

int BlockStmt::eval(SymbolTable & vars)
#line 115 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{
    for(const auto& stmt : l){
        stmt->eval(vars);
    }

    return 0;
}
#line 817 "expr_ast.cpp"

int BlockStmt::isA(int kind) const
{
	if(kind == BlockStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *BlockStmt::getKindName() const
{
	return "BlockStmt";
}

PrintStmt::PrintStmt(Expr * expr)
	: Stmt()
{
	this->kind__ = PrintStmt_kind;
	this->expr = expr;
}

PrintStmt::~PrintStmt()
{
	// not used
}

int PrintStmt::eval(SymbolTable & vars)
#line 123 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{
    std::cout << expr->eval(vars) << std::endl;
    return 0;
}
#line 850 "expr_ast.cpp"

int PrintStmt::isA(int kind) const
{
	if(kind == PrintStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *PrintStmt::getKindName() const
{
	return "PrintStmt";
}

IfStmt::IfStmt(Expr * cond, Stmt * true_blk, Stmt * false_blk)
	: Stmt()
{
	this->kind__ = IfStmt_kind;
	this->cond = cond;
	this->true_blk = true_blk;
	this->false_blk = false_blk;
}

IfStmt::~IfStmt()
{
	// not used
}

int IfStmt::eval(SymbolTable & vars)
#line 128 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{
    if(cond->eval(vars))
        true_blk->eval(vars);
    else if(false_blk != nullptr)
        false_blk->eval(vars);

    return 0;
}
#line 889 "expr_ast.cpp"

int IfStmt::isA(int kind) const
{
	if(kind == IfStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *IfStmt::getKindName() const
{
	return "IfStmt";
}

WhileStmt::WhileStmt(Expr * cond, Stmt * block)
	: Stmt()
{
	this->kind__ = WhileStmt_kind;
	this->cond = cond;
	this->block = block;
}

WhileStmt::~WhileStmt()
{
	// not used
}

int WhileStmt::eval(SymbolTable & vars)
#line 137 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c/expr_ast.tc"
{
    while(cond->eval(vars))
        block->eval(vars);

    return 0;
}
#line 925 "expr_ast.cpp"

int WhileStmt::isA(int kind) const
{
	if(kind == WhileStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *WhileStmt::getKindName() const
{
	return "WhileStmt";
}

}
