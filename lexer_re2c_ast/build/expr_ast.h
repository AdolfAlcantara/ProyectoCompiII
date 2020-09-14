/* expr_ast.h.  Generated automatically by treecc */
#ifndef __yy_expr_ast_h
#define __yy_expr_ast_h
#line 6 "/home/deafdead/Documentos/compiII/proyecto/lexer_re2c_ast/expr_ast.tc"

#include <string>
#include <cstddef>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h> 
#include "Auxiliar.h"

using string_t = std::string;

namespace Ast
{
    class Node;
    using NodeVector = std::vector<Node*>;
    using SymbolTable = std::unordered_map<std::string, int>;
    using SymbolTableGen = std::unordered_map<std::string, std::string>;
}
#line 24 "expr_ast.h"

#include <new>

namespace Ast
{

const int Node_kind = 1;
const int Expr_kind = 2;
const int Stmt_kind = 19;
const int BinaryExpr_kind = 3;
const int NumExpr_kind = 4;
const int IdExpr_kind = 5;
const int InputExpr_kind = 6;
const int ArgList_kind = 22;
const int FuncCall_kind = 31;
const int AddExpr_kind = 7;
const int SubExpr_kind = 8;
const int MulExpr_kind = 9;
const int DivExpr_kind = 10;
const int ModExpr_kind = 11;
const int PwdExpr_kind = 12;
const int GTExpr_kind = 13;
const int LTExpr_kind = 14;
const int GEExpr_kind = 15;
const int LEExpr_kind = 16;
const int EqExpr_kind = 17;
const int NotExpr_kind = 18;
const int AssignStmt_kind = 20;
const int BlockStmt_kind = 21;
const int ForStmt_kind = 23;
const int PrintList_kind = 24;
const int PrintExpr_kind = 25;
const int PrintString_kind = 26;
const int IfStmt_kind = 27;
const int ElseStmt_kind = 28;
const int WhileStmt_kind = 29;
const int FuncDecl_kind = 30;

class Node;
class Expr;
class Stmt;
class BinaryExpr;
class NumExpr;
class IdExpr;
class InputExpr;
class ArgList;
class FuncCall;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class ModExpr;
class PwdExpr;
class GTExpr;
class LTExpr;
class GEExpr;
class LEExpr;
class EqExpr;
class NotExpr;
class AssignStmt;
class BlockStmt;
class ForStmt;
class PrintList;
class PrintExpr;
class PrintString;
class IfStmt;
class ElseStmt;
class WhileStmt;
class FuncDecl;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 108 "expr_ast.h"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual const char *currFilename() const;
	virtual long currLinenum() const;

};

class Node
{
protected:

	int kind__;
	const char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(const char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	Node();

public:

	string_t code;
	int place;

	virtual int eval(SymbolTable & vars) = 0;
	virtual int gen(SymbolTableGen & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Node();

};

class Expr : public Node
{
protected:

	Expr();

public:

	virtual int eval(SymbolTable & vars) = 0;
	virtual int gen(SymbolTableGen & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expr();

};

class Stmt : public Node
{
protected:

	Stmt();

public:

	virtual int eval(SymbolTable & vars) = 0;
	virtual int gen(SymbolTableGen & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Stmt();

};

class BinaryExpr : public Expr
{
protected:

	BinaryExpr(Expr * expr1, Expr * expr2);

public:

	Expr * expr1;
	Expr * expr2;

	virtual int eval(SymbolTable & vars) = 0;
	virtual int gen(SymbolTableGen & vars) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpr();

};

class NumExpr : public Expr
{
public:

	NumExpr(int value);

public:

	int value;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NumExpr();

};

class IdExpr : public Expr
{
public:

	IdExpr(string_t id);

public:

	string_t id;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdExpr();

};

class InputExpr : public Expr
{
public:

	InputExpr(string_t text);

public:

	string_t text;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~InputExpr();

};

class ArgList : public Expr
{
public:

	ArgList(NodeVector args);

public:

	NodeVector args;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArgList();

};

class FuncCall : public Expr
{
public:

	FuncCall(string_t name, ArgList * args);

public:

	string_t name;
	ArgList * args;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FuncCall();

};

class AddExpr : public BinaryExpr
{
public:

	AddExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class SubExpr : public BinaryExpr
{
public:

	SubExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class MulExpr : public BinaryExpr
{
public:

	MulExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MulExpr();

};

class DivExpr : public BinaryExpr
{
public:

	DivExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};

class ModExpr : public BinaryExpr
{
public:

	ModExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpr();

};

class PwdExpr : public BinaryExpr
{
public:

	PwdExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PwdExpr();

};

class GTExpr : public BinaryExpr
{
public:

	GTExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GTExpr();

};

class LTExpr : public BinaryExpr
{
public:

	LTExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LTExpr();

};

class GEExpr : public BinaryExpr
{
public:

	GEExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GEExpr();

};

class LEExpr : public BinaryExpr
{
public:

	LEExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LEExpr();

};

class EqExpr : public BinaryExpr
{
public:

	EqExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EqExpr();

};

class NotExpr : public BinaryExpr
{
public:

	NotExpr(Expr * expr1, Expr * expr2);

public:

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotExpr();

};

class AssignStmt : public Stmt
{
public:

	AssignStmt(string_t id, Expr * expr);

public:

	string_t id;
	Expr * expr;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignStmt();

};

class BlockStmt : public Stmt
{
public:

	BlockStmt(NodeVector l);

public:

	NodeVector l;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BlockStmt();

};

class ForStmt : public Stmt
{
public:

	ForStmt(string_t id, ArgList * args, Stmt * blck_stmts);

public:

	string_t id;
	ArgList * args;
	Stmt * blck_stmts;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ForStmt();

};

class PrintList : public Stmt
{
public:

	PrintList(NodeVector vals);

public:

	NodeVector vals;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintList();

};

class PrintExpr : public Stmt
{
public:

	PrintExpr(Expr * expr);

public:

	Expr * expr;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintExpr();

};

class PrintString : public Stmt
{
public:

	PrintString(string_t literal);

public:

	string_t literal;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintString();

};

class IfStmt : public Stmt
{
public:

	IfStmt(Expr * cond, Stmt * true_blk, Stmt * false_blk);

public:

	Expr * cond;
	Stmt * true_blk;
	Stmt * false_blk;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class ElseStmt : public Stmt
{
public:

	ElseStmt(Stmt * code_blk);

public:

	Stmt * code_blk;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ElseStmt();

};

class WhileStmt : public Stmt
{
public:

	WhileStmt(Expr * cond, Stmt * block);

public:

	Expr * cond;
	Stmt * block;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};

class FuncDecl : public Stmt
{
public:

	FuncDecl(string_t name, ArgList * args, Stmt * code_blk);

public:

	string_t name;
	ArgList * args;
	Stmt * code_blk;

	virtual int eval(SymbolTable & vars);
	virtual int gen(SymbolTableGen & vars);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FuncDecl();

};



}
#endif
