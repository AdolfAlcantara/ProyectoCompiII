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
#line 163 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return value;
}
#line 418 "expr_ast.cpp"

int NumExpr::gen(SymbolTableGen & vars)
#line 390 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 167 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    auto it = vars.find(id);

    if(it != vars.end())
        return it->second;
    else
        throw std::exception();
}
#line 465 "expr_ast.cpp"

int IdExpr::gen(SymbolTableGen & vars)
#line 397 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 176 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::cout<<text;
    int val;
    std::cin>>val;
    return val;
}
#line 512 "expr_ast.cpp"

int InputExpr::gen(SymbolTableGen & vars)
#line 406 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    place = aux.getReg();
    
    code = "addi\t\t $sp, $sp, -4\n";
    code += "sw\t\t $ra, 0($sp)\n";
    
    code += "jal read_int\n";
    code+= "move\t\t $t"+aux.to_str(place)+", $v0\n";

    code += "lw\t\t $ra, 0($sp)\n";
    code += "addi\t\t $sp, $sp, 4\n";
    return 0;
}
#line 529 "expr_ast.cpp"

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
#line 210 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    for(const auto& arg : args){
        arg->eval(vars);
    }
    return 0; 
}
#line 564 "expr_ast.cpp"

int ArgList::gen(SymbolTableGen & vars)
#line 443 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 580 "expr_ast.cpp"

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
#line 277 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 613 "expr_ast.cpp"

int FuncCall::gen(SymbolTableGen & vars)
#line 612 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    args->gen(vars);
    code = args->code;
    std::string _name = aux.getLabel(name);
    code += "addi\t\t $sp, $sp, -4\n";
    code += "sw\t\t $ra, 0($sp)\n";
    code += "jal\t\t "+_name+"\n\n";
    code += "lw\t\t $ra, 0($sp)\n";
    code += "addi\t\t $sp, $sp, 4\n";
    return 0;
}
#line 628 "expr_ast.cpp"

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

ArrayExpr::ArrayExpr(string_t name, Expr * exprPos)
	: Expr()
{
	this->kind__ = ArrayExpr_kind;
	this->name = name;
	this->exprPos = exprPos;
}

ArrayExpr::~ArrayExpr()
{
	// not used
}

int ArrayExpr::eval(SymbolTable & vars)
#line 191 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 661 "expr_ast.cpp"

int ArrayExpr::gen(SymbolTableGen & vars)
#line 642 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 668 "expr_ast.cpp"

int ArrayExpr::isA(int kind) const
{
	if(kind == ArrayExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *ArrayExpr::getKindName() const
{
	return "ArrayExpr";
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
#line 150 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) + expr2->eval(vars);}
#line 697 "expr_ast.cpp"

int AddExpr::gen(SymbolTableGen & vars)
#line 288 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 714 "expr_ast.cpp"

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
#line 151 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) - expr2->eval(vars);}
#line 743 "expr_ast.cpp"

int SubExpr::gen(SymbolTableGen & vars)
#line 303 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 760 "expr_ast.cpp"

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
#line 152 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) * expr2->eval(vars);}
#line 789 "expr_ast.cpp"

int MulExpr::gen(SymbolTableGen & vars)
#line 317 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 794 "expr_ast.cpp"

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
#line 153 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) / expr2->eval(vars);}
#line 823 "expr_ast.cpp"

int DivExpr::gen(SymbolTableGen & vars)
#line 318 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 828 "expr_ast.cpp"

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
#line 154 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) % expr2->eval(vars);}
#line 857 "expr_ast.cpp"

int ModExpr::gen(SymbolTableGen & vars)
#line 319 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 862 "expr_ast.cpp"

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
#line 155 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return pow(expr1->eval(vars), expr2->eval(vars));}
#line 891 "expr_ast.cpp"

int PwdExpr::gen(SymbolTableGen & vars)
#line 320 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 896 "expr_ast.cpp"

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
#line 156 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) > expr2->eval(vars);}
#line 925 "expr_ast.cpp"

int GTExpr::gen(SymbolTableGen & vars)
#line 322 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 940 "expr_ast.cpp"

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
#line 157 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) < expr2->eval(vars);}
#line 969 "expr_ast.cpp"

int LTExpr::gen(SymbolTableGen & vars)
#line 334 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 984 "expr_ast.cpp"

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
#line 158 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) >= expr2->eval(vars);}
#line 1013 "expr_ast.cpp"

int GEExpr::gen(SymbolTableGen & vars)
#line 345 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{return 0;}
#line 1018 "expr_ast.cpp"

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
#line 159 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) <= expr2->eval(vars);}
#line 1047 "expr_ast.cpp"

int LEExpr::gen(SymbolTableGen & vars)
#line 347 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    
    return 0;
}
#line 1055 "expr_ast.cpp"

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
#line 160 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) == expr2->eval(vars);}
#line 1084 "expr_ast.cpp"

int EqExpr::gen(SymbolTableGen & vars)
#line 352 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 1105 "expr_ast.cpp"

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
#line 161 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ return expr1->eval(vars) != expr2->eval(vars);}
#line 1134 "expr_ast.cpp"

int NotExpr::gen(SymbolTableGen & vars)
#line 371 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 1154 "expr_ast.cpp"

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
#line 195 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    int value = expr->eval(vars);
    vars[id] = value;

    return 0;
}
#line 1190 "expr_ast.cpp"

int AssignStmt::gen(SymbolTableGen & vars)
#line 420 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 1206 "expr_ast.cpp"

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
#line 202 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    for(const auto& stmt : l){
        stmt->eval(vars);
    }

    return 0;
}
#line 1242 "expr_ast.cpp"

int BlockStmt::gen(SymbolTableGen & vars)
#line 433 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    code = "";
    for(const auto& stmt : l){
        stmt->gen(vars);
        code += stmt->code;
    }

    return 0;
}
#line 1255 "expr_ast.cpp"

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
#line 217 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 1301 "expr_ast.cpp"

int ForStmt::gen(SymbolTableGen & vars)
#line 456 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 1340 "expr_ast.cpp"

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
#line 243 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    for(const auto& p : vals){
        p->eval(vars);
    }
    std::cout<<std::endl;
    return 0;
}
#line 1376 "expr_ast.cpp"

int PrintList::gen(SymbolTableGen & vars)
#line 492 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    code = "";
    for(const auto& val : vals){
        val->gen(vars);
        code += val->code;
    }
    return 0;
}
#line 1388 "expr_ast.cpp"

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
#line 233 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::cout << expr->eval(vars);
    return 0;
}
#line 1421 "expr_ast.cpp"

int PrintExpr::gen(SymbolTableGen & vars)
#line 502 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{ 
    expr->gen(vars);

    code = expr->code;
    code += "addi\t\t $sp, $sp, -4\n";
    code += "sw\t\t $ra, 0($sp)\n";

    code+= "move\t\t $a0,$t"+aux.to_str(expr->place)+"\n";
    code+= "jal\t\t print_int\n";

    code += "lw\t\t $ra, 0($sp)\n";
    code += "addi\t\t $sp, $sp, 4\n";

    aux.freeReg(expr->place);
    return 0;
}
#line 1441 "expr_ast.cpp"

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
#line 238 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    std::cout<<literal;
    return 0;
}
#line 1474 "expr_ast.cpp"

int PrintString::gen(SymbolTableGen & vars)
#line 520 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    string_t var = aux.saveVar(vars,literal,2);
    code = "addi\t\t $sp, $sp, -4\n";
    code += "sw\t\t $ra, 0($sp)\n";

    code += "la\t\t $a0,"+var+"\n";
    code+= "jal\t\t print_str\n";
    
    code += "lw\t\t $ra, 0($sp)\n";
    code += "addi\t\t $sp, $sp, 4\n";
    return 0;
}
#line 1490 "expr_ast.cpp"

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
#line 251 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    if(cond->eval(vars))
        true_blk->eval(vars);
    else if(false_blk != nullptr)
        false_blk->eval(vars);

    return 0;
}
#line 1529 "expr_ast.cpp"

int IfStmt::gen(SymbolTableGen & vars)
#line 534 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 1553 "expr_ast.cpp"

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
#line 260 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    if(code_blk != nullptr){
        code_blk->eval(vars);
    }
    return 0;
}
#line 1588 "expr_ast.cpp"

int ElseStmt::gen(SymbolTableGen & vars)
#line 556 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    if(code_blk != nullptr){
        std::string label_else = aux.labelGenerator("else");
        code_blk->gen(vars);
        code = "\n"+label_else+":\n\n";
        code+= code_blk->code;
    }
    return 0;
}
#line 1601 "expr_ast.cpp"

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
#line 267 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    while(cond->eval(vars))
        block->eval(vars);
    return 0;
}
#line 1636 "expr_ast.cpp"

int WhileStmt::gen(SymbolTableGen & vars)
#line 567 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
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
#line 1660 "expr_ast.cpp"

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
#line 273 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 1694 "expr_ast.cpp"

int FuncDecl::gen(SymbolTableGen & vars)
#line 589 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    int parameter_count = 0;
    code = "";
    std::string label_func = aux.labelGenerator(name);
    aux.saveLabel(name, label_func); 

    code+= "\n"+label_func+":\n\n";
    for(const auto& arg : args->args){
        std::string parameter = reinterpret_cast<Ast::IdExpr*>(arg)->id;
        
        aux.saveVar(vars,parameter,1);
        int temp = aux.getReg();
        code+= "la\t\t $t"+aux.to_str(temp)+", "+parameter+"\n";
        code+= "sw\t\t $a"+aux.to_str(parameter_count++)+", 0($t"+aux.to_str(temp)+")\n";
        aux.freeReg(temp);
    }
    
    code_blk->gen(vars);
    code += code_blk->code;

    return 0;
}
#line 1720 "expr_ast.cpp"

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

ReturnStmt::ReturnStmt(Expr * expr)
	: Stmt()
{
	this->kind__ = ReturnStmt_kind;
	this->expr = expr;
}

ReturnStmt::~ReturnStmt()
{
	// not used
}

int ReturnStmt::eval(SymbolTable & vars)
#line 281 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 1752 "expr_ast.cpp"

int ReturnStmt::gen(SymbolTableGen & vars)
#line 624 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    expr->gen(vars);

    place = expr->place;
    code = expr->code;
    code += "jr\t\t $ra\n";

    return 0;
}
#line 1765 "expr_ast.cpp"

int ReturnStmt::isA(int kind) const
{
	if(kind == ReturnStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ReturnStmt::getKindName() const
{
	return "ReturnStmt";
}

ArrayDecl::ArrayDecl(string_t name, ArgList * args)
	: Stmt()
{
	this->kind__ = ArrayDecl_kind;
	this->name = name;
	this->args = args;
}

ArrayDecl::~ArrayDecl()
{
	// not used
}

int ArrayDecl::eval(SymbolTable & vars)
#line 183 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 1798 "expr_ast.cpp"

int ArrayDecl::gen(SymbolTableGen & vars)
#line 634 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 1805 "expr_ast.cpp"

int ArrayDecl::isA(int kind) const
{
	if(kind == ArrayDecl_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ArrayDecl::getKindName() const
{
	return "ArrayDecl";
}

ArrayStmt::ArrayStmt(string_t name, Expr * exprPos, Expr * exprRHS)
	: Stmt()
{
	this->kind__ = ArrayStmt_kind;
	this->name = name;
	this->exprPos = exprPos;
	this->exprRHS = exprRHS;
}

ArrayStmt::~ArrayStmt()
{
	// not used
}

int ArrayStmt::eval(SymbolTable & vars)
#line 187 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 1839 "expr_ast.cpp"

int ArrayStmt::gen(SymbolTableGen & vars)
#line 638 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"
{
    return 0;
}
#line 1846 "expr_ast.cpp"

int ArrayStmt::isA(int kind) const
{
	if(kind == ArrayStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ArrayStmt::getKindName() const
{
	return "ArrayStmt";
}

}
