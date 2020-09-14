/* expr_ast.cpp.  Generated automatically by treecc */
#line 27 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"

    #include "expr_ast.h"
    Auxiliar aux;
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
void *Node::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Node::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Node::Node()
{
	this->kind__ = Node_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

Node::~Node()
{
	// not used
}

int Node::isA(int kind) const
{
	if(kind == Node_kind)
		return 1;
	else
		return 0;
}

const char *Node::getKindName() const
{
	return "Node";
}

Expr::Expr()
	: Node()
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
		return Node::isA(kind);
}

const char *Expr::getKindName() const
{
	return "Expr";
}

Stmt::Stmt()
	: Node()
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
		return Node::isA(kind);
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
#line 143 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return value;
}
#line 418 "expr_ast.cpp"

int NumExpr::gen(SymbolTableGen & vars)
#line 354 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    place = aux.getReg();

    code = "li\t\t $t"+aux.to_str(place)+", "+aux.to_str(value) + "\n";
    return 0;
}
#line 428 "expr_ast.cpp"

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
#line 147 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    auto it = vars.find(id);

    if(it != vars.end())
        return it->second;
    else
        throw std::exception();
}
#line 465 "expr_ast.cpp"

int IdExpr::gen(SymbolTableGen & vars)
#line 361 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::cout<<"IdExpr:\n";
    place  = aux.getReg();
    
    code = "la\t\t $t"+aux.to_str(place)+", "+id+"\n";
    code += "lw\t\t $t"+aux.to_str(place)+", 0($t"+aux.to_str(place)+")\n";
    return 0;
}
#line 477 "expr_ast.cpp"

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

InputExpr::InputExpr(string_t text)
	: Expr()
{
	this->kind__ = InputExpr_kind;
	this->text = text;
}

InputExpr::~InputExpr()
{
	// not used
}

int InputExpr::eval(SymbolTable & vars)
#line 156 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::cout<<text;
    int val;
    std::cin>>val;
    return val;
}
#line 512 "expr_ast.cpp"

int InputExpr::gen(SymbolTableGen & vars)
#line 370 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    place = aux.getReg();
    
    code = "jal read_int\n";
    code+= "move\t\t $t"+aux.to_str(place)+", $v0\n";
    return 0;
}
#line 523 "expr_ast.cpp"

int InputExpr::isA(int kind) const
{
	if(kind == InputExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *InputExpr::getKindName() const
{
	return "InputExpr";
}

ArgList::ArgList(NodeVector args)
	: Expr()
{
	this->kind__ = ArgList_kind;
	this->args = args;
}

ArgList::~ArgList()
{
	// not used
}

int ArgList::eval(SymbolTable & vars)
#line 178 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    for(const auto& arg : args){
        arg->eval(vars);
    }
    return 0; 
}
#line 558 "expr_ast.cpp"

int ArgList::gen(SymbolTableGen & vars)
#line 401 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    code ="";
    for(const auto& arg : args){
        int x = aux.getArg();
        arg->gen(vars);
        code+=arg->code;
        code+="move\t\t $a"+aux.to_str(x)+", $t"+aux.to_str(arg->place)+"\n";
        aux.freeReg(arg->place);
    }
    aux.freeArgs();
    return 0; 
}
#line 574 "expr_ast.cpp"

int ArgList::isA(int kind) const
{
	if(kind == ArgList_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *ArgList::getKindName() const
{
	return "ArgList";
}

FuncCall::FuncCall(string_t name, ArgList * args)
	: Expr()
{
	this->kind__ = FuncCall_kind;
	this->name = name;
	this->args = args;
}

FuncCall::~FuncCall()
{
	// not used
}

int FuncCall::eval(SymbolTable & vars)
#line 245 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 607 "expr_ast.cpp"

int FuncCall::gen(SymbolTableGen & vars)
#line 559 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    args->gen(vars);
    code = args->code;
    
    code += "addi\t\t $sp, $sp, -4\n";
    code += "sw\t\t $ra, 0($sp)\n";
    code += "jal\t\t "+name+"\n\n";
    code += "lw\t\t $ra, 0($sp)\n";
    code += "addi\t\t $sp, $sp, 4\n";
    return 0;
}
#line 622 "expr_ast.cpp"

int FuncCall::isA(int kind) const
{
	if(kind == FuncCall_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *FuncCall::getKindName() const
{
	return "FuncCall";
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
#line 130 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) + expr2->eval(vars);}
#line 651 "expr_ast.cpp"

int AddExpr::gen(SymbolTableGen & vars)
#line 252 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr1->gen(vars);
    expr2->gen(vars);

    place = aux.getReg();

    code = expr1->code + expr2->code;
    code += "add\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr2->place) + "\n";

    aux.freeReg(expr1->place);
    aux.freeReg(expr2->place);
    return 0;
}
#line 668 "expr_ast.cpp"

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
#line 131 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) - expr2->eval(vars);}
#line 697 "expr_ast.cpp"

int SubExpr::gen(SymbolTableGen & vars)
#line 267 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr1->gen(vars);
    expr2->gen(vars);

    place = aux.getReg();

    code = expr1->code + expr2->code;
    code += "sub\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr2->place) + "\n";

    aux.freeReg(expr1->place);
    aux.freeReg(expr2->place);
    return 0;
}
#line 714 "expr_ast.cpp"

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
#line 132 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) * expr2->eval(vars);}
#line 743 "expr_ast.cpp"

int MulExpr::gen(SymbolTableGen & vars)
#line 281 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 748 "expr_ast.cpp"

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
#line 133 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) / expr2->eval(vars);}
#line 777 "expr_ast.cpp"

int DivExpr::gen(SymbolTableGen & vars)
#line 282 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 782 "expr_ast.cpp"

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

ModExpr::ModExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = ModExpr_kind;
}

ModExpr::~ModExpr()
{
	// not used
}

int ModExpr::eval(SymbolTable & vars)
#line 134 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) % expr2->eval(vars);}
#line 811 "expr_ast.cpp"

int ModExpr::gen(SymbolTableGen & vars)
#line 283 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 816 "expr_ast.cpp"

int ModExpr::isA(int kind) const
{
	if(kind == ModExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *ModExpr::getKindName() const
{
	return "ModExpr";
}

PwdExpr::PwdExpr(Expr * expr1, Expr * expr2)
	: BinaryExpr(expr1, expr2)
{
	this->kind__ = PwdExpr_kind;
}

PwdExpr::~PwdExpr()
{
	// not used
}

int PwdExpr::eval(SymbolTable & vars)
#line 135 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return pow(expr1->eval(vars), expr2->eval(vars));}
#line 845 "expr_ast.cpp"

int PwdExpr::gen(SymbolTableGen & vars)
#line 284 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 850 "expr_ast.cpp"

int PwdExpr::isA(int kind) const
{
	if(kind == PwdExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *PwdExpr::getKindName() const
{
	return "PwdExpr";
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
#line 136 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) > expr2->eval(vars);}
#line 879 "expr_ast.cpp"

int GTExpr::gen(SymbolTableGen & vars)
#line 286 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr1->gen(vars);
    expr2->gen(vars);

    place = aux.getReg();
    code = expr1->code + expr2->code;
    code+="slt\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr2->place)+", $t"+aux.to_str(expr1->place)+"\n";
    aux.freeReg(expr1->place);
    aux.freeReg(expr2->place);
    return 0;
}
#line 894 "expr_ast.cpp"

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
#line 137 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) < expr2->eval(vars);}
#line 923 "expr_ast.cpp"

int LTExpr::gen(SymbolTableGen & vars)
#line 298 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr1->gen(vars);
    expr2->gen(vars);

    place = aux.getReg();
    code = expr1->code + expr2->code;
    code+="slt\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr2->place)+"\n";
    aux.freeReg(expr1->place);
    aux.freeReg(expr2->place);
    return 0;
}
#line 938 "expr_ast.cpp"

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
#line 138 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) >= expr2->eval(vars);}
#line 967 "expr_ast.cpp"

int GEExpr::gen(SymbolTableGen & vars)
#line 309 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 972 "expr_ast.cpp"

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
#line 139 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) <= expr2->eval(vars);}
#line 1001 "expr_ast.cpp"

int LEExpr::gen(SymbolTableGen & vars)
#line 311 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    
    return 0;
}
#line 1009 "expr_ast.cpp"

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
#line 140 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) == expr2->eval(vars);}
#line 1038 "expr_ast.cpp"

int EqExpr::gen(SymbolTableGen & vars)
#line 316 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr1->gen(vars);
    expr2->gen(vars);

    place = aux.getReg();

    code = expr1->code + expr2->code;
    code += "sub\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr2->place) + "\n";
    code += "slt\t\t $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(place)+", $zero\n";
    code += "slt\t\t $t"+aux.to_str(expr2->place)+", $zero, $t"+aux.to_str(place)+"\n";
    code += "xori\t\t $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr1->place)+", 1\n";
    code += "xori\t\t $t"+aux.to_str(expr2->place)+", $t"+aux.to_str(expr2->place)+", 0\n";
    code += "xor\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr2->place)+"\n";
    aux.freeReg(expr1->place);
    aux.freeReg(expr2->place);
    return 0;
}
#line 1059 "expr_ast.cpp"

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
#line 141 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) != expr2->eval(vars);}
#line 1088 "expr_ast.cpp"

int NotExpr::gen(SymbolTableGen & vars)
#line 335 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr1->gen(vars);
    expr2->gen(vars);

    place = aux.getReg();

    code = expr1->code + expr2->code;
    code += "sub\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr2->place) + "\n";
    code += "slt\t\t $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(place)+", $zero\n";
    code += "slt\t\t $t"+aux.to_str(expr2->place)+", $zero, $t"+aux.to_str(place)+"\n";
    code += "xor\t\t $t"+aux.to_str(place)+", $t"+aux.to_str(expr1->place)+", $t"+aux.to_str(expr2->place)+"\n";
    aux.freeReg(expr1->place);
    aux.freeReg(expr2->place);
    return 0;
    
}
#line 1108 "expr_ast.cpp"

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
#line 163 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    int value = expr->eval(vars);
    vars[id] = value;

    return 0;
}
#line 1144 "expr_ast.cpp"

int AssignStmt::gen(SymbolTableGen & vars)
#line 378 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr->gen(vars);

    place = aux.getReg();
    aux.saveVar(vars,id,1);
    code = expr->code;
    code += "la\t\t $t"+aux.to_str(place)+", "+id+"\n";
    code += "sw\t\t $t"+aux.to_str(expr->place)+", 0($t"+aux.to_str(place)+")\n";

    aux.freeReg(expr->place);
    return 0;
}
#line 1160 "expr_ast.cpp"

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
#line 170 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    for(const auto& stmt : l){
        stmt->eval(vars);
    }

    return 0;
}
#line 1196 "expr_ast.cpp"

int BlockStmt::gen(SymbolTableGen & vars)
#line 391 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    code = "";
    for(const auto& stmt : l){
        stmt->gen(vars);
        code += stmt->code;
    }

    return 0;
}
#line 1209 "expr_ast.cpp"

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

ForStmt::ForStmt(string_t id, ArgList * args, Stmt * blck_stmts)
	: Stmt()
{
	this->kind__ = ForStmt_kind;
	this->id = id;
	this->args = args;
	this->blck_stmts = blck_stmts;
}

ForStmt::~ForStmt()
{
	// not used
}

int ForStmt::eval(SymbolTable & vars)
#line 185 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    // int second = args->args.back()->eval(vars);
    // std::cout<<"second: "<<second<<std::endl;
    // args->args.pop_back();
    // int first = args->args.back()->eval(vars);
    // std::cout<<"first: "<<first<<std::endl;
    // vars[id] = first;
    // int i = first;
    // for(;i<second;){
    //     blck_stmts->eval(vars);
    //     i++;
    //     vars[id] = i;
    // }
    return 0;
}
#line 1255 "expr_ast.cpp"

int ForStmt::gen(SymbolTableGen & vars)
#line 414 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    args->gen(vars);
    code = args->code;
    int start = aux.getReg();
    int end = aux.getReg();
    code+= "move\t\t $t"+aux.to_str(start)+", $a0\n";
    code+= "move\t\t $t"+aux.to_str(end)+", $a1\n";
    aux.saveVar(vars,id,1);
    int temp = aux.getReg();
    code += "la\t\t $t"+aux.to_str(temp)+", "+id+"\n";
    code += "sw\t\t $t"+aux.to_str(start)+", 0($t"+aux.to_str(temp)+")\n";
    aux.freeReg(temp);

    std::string label_for = aux.labelGenerator("for");
    std::string label_end_for = aux.labelGenerator("end_for");
    code += label_for+":\n\n";
    temp = aux.getReg();
    code += "slt\t\t $t"+aux.to_str(temp)+", $t"+aux.to_str(start)+", $t"+aux.to_str(end)+"\n";
    code += "beq\t\t $t"+aux.to_str(temp)+", $zero, "+label_end_for+"\n\n";
    aux.freeReg(temp);
    blck_stmts->gen(vars);
    code += blck_stmts->code;

    code += "addi\t\t $t"+aux.to_str(start)+", $t"+aux.to_str(start)+", 1\n";
    temp = aux.getReg();
    code += "la\t\t $t"+aux.to_str(temp)+", "+id+"\n";
    code += "sw\t\t $t"+aux.to_str(start)+", 0($t"+aux.to_str(temp)+")\n";
    aux.freeReg(temp);
    code+="j\t\t "+label_for+"\n";

    code+="\n"+label_end_for+":\n\n";
    aux.freeReg(start);
    aux.freeReg(end);
    return 0;
}
#line 1294 "expr_ast.cpp"

int ForStmt::isA(int kind) const
{
	if(kind == ForStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ForStmt::getKindName() const
{
	return "ForStmt";
}

PrintList::PrintList(NodeVector vals)
	: Stmt()
{
	this->kind__ = PrintList_kind;
	this->vals = vals;
}

PrintList::~PrintList()
{
	// not used
}

int PrintList::eval(SymbolTable & vars)
#line 211 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    for(const auto& p : vals){
        p->eval(vars);
    }
    std::cout<<std::endl;
    return 0;
}
#line 1330 "expr_ast.cpp"

int PrintList::gen(SymbolTableGen & vars)
#line 450 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    code = "";
    for(const auto& val : vals){
        val->gen(vars);
        code += val->code;
    }
    return 0;
}
#line 1342 "expr_ast.cpp"

int PrintList::isA(int kind) const
{
	if(kind == PrintList_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *PrintList::getKindName() const
{
	return "PrintList";
}

PrintExpr::PrintExpr(Expr * expr)
	: Stmt()
{
	this->kind__ = PrintExpr_kind;
	this->expr = expr;
}

PrintExpr::~PrintExpr()
{
	// not used
}

int PrintExpr::eval(SymbolTable & vars)
#line 201 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::cout << expr->eval(vars);
    return 0;
}
#line 1375 "expr_ast.cpp"

int PrintExpr::gen(SymbolTableGen & vars)
#line 460 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ 
    expr->gen(vars);

    code = expr->code;
    code+= "move\t\t $a0,$t"+aux.to_str(expr->place)+"\n";
    code+= "jal\t\t print_int\n";

    aux.freeReg(expr->place);
    return 0;
}
#line 1389 "expr_ast.cpp"

int PrintExpr::isA(int kind) const
{
	if(kind == PrintExpr_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *PrintExpr::getKindName() const
{
	return "PrintExpr";
}

PrintString::PrintString(string_t literal)
	: Stmt()
{
	this->kind__ = PrintString_kind;
	this->literal = literal;
}

PrintString::~PrintString()
{
	// not used
}

int PrintString::eval(SymbolTable & vars)
#line 206 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::cout<<literal;
    return 0;
}
#line 1422 "expr_ast.cpp"

int PrintString::gen(SymbolTableGen & vars)
#line 472 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    string_t var = aux.saveVar(vars,literal,2);
    code = "la\t\t $a0,"+var+"\n";
    code+= "jal\t\t print_str\n";

    return 0;
}
#line 1433 "expr_ast.cpp"

int PrintString::isA(int kind) const
{
	if(kind == PrintString_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *PrintString::getKindName() const
{
	return "PrintString";
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
#line 219 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    if(cond->eval(vars))
        true_blk->eval(vars);
    else if(false_blk != nullptr)
        false_blk->eval(vars);

    return 0;
}
#line 1472 "expr_ast.cpp"

int IfStmt::gen(SymbolTableGen & vars)
#line 481 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    cond->gen(vars);
    code = cond->code;
    std::string label_if = aux.labelGenerator("if");
    std::string label_end_if = aux.labelGenerator("end_if");
    code+= "\n"+label_if+":\n\n";
    code+= "beq\t\t $t"+aux.to_str(cond->place)+", $zero, "+label_end_if +"\n";
    aux.freeReg(cond->place);

    true_blk->gen(vars);
    code+= true_blk->code;
    code+="\n"+label_end_if+":\n\n";

    if(false_blk != nullptr){
        false_blk->gen(vars);
        code+= false_blk->code;
    }

    return 0;
}
#line 1496 "expr_ast.cpp"

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

ElseStmt::ElseStmt(Stmt * code_blk)
	: Stmt()
{
	this->kind__ = ElseStmt_kind;
	this->code_blk = code_blk;
}

ElseStmt::~ElseStmt()
{
	// not used
}

int ElseStmt::eval(SymbolTable & vars)
#line 228 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    if(code_blk != nullptr){
        code_blk->eval(vars);
    }
    return 0;
}
#line 1531 "expr_ast.cpp"

int ElseStmt::gen(SymbolTableGen & vars)
#line 503 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    if(code_blk != nullptr){
        std::string label_else = aux.labelGenerator("else");
        code_blk->gen(vars);
        code = "\n"+label_else+":\n\n";
        code+= code_blk->code;
    }
    return 0;
}
#line 1544 "expr_ast.cpp"

int ElseStmt::isA(int kind) const
{
	if(kind == ElseStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ElseStmt::getKindName() const
{
	return "ElseStmt";
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
#line 235 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    while(cond->eval(vars))
        block->eval(vars);
    return 0;
}
#line 1579 "expr_ast.cpp"

int WhileStmt::gen(SymbolTableGen & vars)
#line 514 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::string label_while = aux.labelGenerator("while");
    code = "\n"+label_while+":\n";
    cond->gen(vars);
    code += cond->code;

    std::string label_end_while = aux.labelGenerator("while_end");
    code += "beq\t\t $t"+aux.to_str(cond->place)+", $zero, "+label_end_while+"\n";

    aux.freeReg(cond->place);
    block->gen(vars);

    code += block->code;

    code += "j\t\t "+label_while+"\n";
    
    code += "\n"+label_end_while+":\n";

    return 0;
}
#line 1603 "expr_ast.cpp"

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

FuncDecl::FuncDecl(string_t name, ArgList * args, Stmt * code_blk)
	: Stmt()
{
	this->kind__ = FuncDecl_kind;
	this->name = name;
	this->args = args;
	this->code_blk = code_blk;
}

FuncDecl::~FuncDecl()
{
	// not used
}

int FuncDecl::eval(SymbolTable & vars)
#line 241 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 1637 "expr_ast.cpp"

int FuncDecl::gen(SymbolTableGen & vars)
#line 536 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    args->gen(vars);
    code = args->code;

    std::string label_func = aux.labelGenerator(name);
    int label_pos = aux.getReg();
    int func_name = aux.getReg();
    aux.saveVar(vars,name,1);
    code += "la\t\t $t"+aux.to_str(label_pos)+", "+label_func+"\n";
    code += "la\t\t $t"+aux.to_str(func_name)+", "+name+"\n";
    code += "sw\t\t $t"+aux.to_str(label_pos)+", 0($t"+aux.to_str(func_name)+")\n";
    
    aux.freeReg(label_pos);
    aux.freeReg(func_name); 

    code+= "\n"+label_func+":\n\n";
    
    code_blk->gen(vars);
    code += code_blk->code;

    return 0;
}
#line 1663 "expr_ast.cpp"

int FuncDecl::isA(int kind) const
{
	if(kind == FuncDecl_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *FuncDecl::getKindName() const
{
	return "FuncDecl";
}

}
