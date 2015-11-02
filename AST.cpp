#include <bits/stdc++.h>

class ast_node
{
};

class program
{


};

class operator_node
{


};

class field_decl_list
{

};

class field_decl
{

};

class type
{

};

class identifier_array
{

};

class statement_decl_list
{

};

class statement_decl
{

};



class assign_op
{

};

class method_call
{

};

class method_name
{

};

class expr_list
{

};

class callout_arg_list
{

};

class callout_arg
{

};

class literal
{

};

class int_literal
{

};

class char_literal
{

};

class bool_literal
{

};



// For All expressions 

class expr:public ast_node
{
protected:
	int num;
public:
	virtual int evaluate()=0;

};

class location:public expr
{
protected:
	int loc;
public:
	location(int locs)
	{
		loc = locs;
	}

	int evaluate()

	{
		return loc;
	}
	

};

class unary_minus:public expr
{
protected:
	expr *expression;
public:
	unary_minus(expr* express)
	{
		expression = express;
	}
	int evaluate()
	{
		int num;
		num = expression->evaluate();
		return (-num);
	}

};

class unary_not:public expr
{
protected:
	expr *expression;
public:
	unary_not(expr* express)
	{
		expression = express;
	}
	int evaluate()
	{
		int num;
		num = expression->evaluate();
		return (!num);
	}

};

class plus:public expr
{
protected:
	expr *left;
	expr *right;
public:
	plus(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num + right_num;
		return num;
	}

};

class minus:public expr
{
protected:
	expr *left;
	expr *right;
public:
	minus(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num - right_num;
		return num;
	}

};

class multiply:public expr
{
protected:
	expr *left;
	expr *right;
public:
	multiply(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num * right_num;
		return num;
	}

};

class divide:public expr
{
protected:
	expr *left;
	expr *right;
public:
	divide(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num / right_num;
		return num;
	}

};

class modulo:public expr
{
protected:
	expr *left;
	expr *right;
public:
	modulo(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num % right_num;
		return num;
	}

};

class rel_op : public expr
{
protected:
	expr *left;
	expr *right;
public:
	rel_op()
	{
		left = NULL;
		right = NULL;
	}
};

class less_than : public rel_op
{
public:
	less_than(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num < right_num;
		return num;
	}


};

class less_equal : public rel_op
{
	public:
	less_equal(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num <= right_num;
		return num;
	}


};

class greater_than : public rel_op
{
	public:
	greater_than(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num < right_num;
		return num;
	}
};

class greater_equal : public rel_op
{
public:
	greater_equal(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num < right_num;
		return num;
	}
};

class eq_op : public expr
{
protected:
	expr *left;
	expr *right;
public:
	eq_op() 
	{
		left = NULL;
		right = NULL;
	}
};

class equal_equal : public eq_op
{
public:
	equal_equal(expr *l, expr *r)
	{
		left = l;
		right = r;
	}	

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num == right_num;
	}
};

class not_equal : public eq_op
{
public:
	not_equal(expr *l, expr *r)
	{
		left = l;
		right = r;
	}	

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num != right_num;
	}
};


class cond_op : public expr
{
protected:
	expr *left;
	expr *right;
public:
	cond_op()
	{
		left = NULL;
		right = NULL;
	}	
};

class and_op:public cond_op
{
public:
	and_op(expr *l, expr *r)
	{
		left = l;
		right = r;
	}	

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num && right_num;

	}

};

class or_op:public cond_op
{
public:
	or_op(expr *l, expr *r)
	{
		left = l;
		right = r;
	}	

	int evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num || right_num;
		return num;
	}
};


class int_value : public int_literal
{
protected:
	int num;
public:
	 int_value(int value)
	{
		num = value;
	}
};

class char_value : public char_literal
{
protected:
	char character;
public:
	 char_value(char value)
	{
		character = value;
	}

};

class bool_true : public bool_literal
{
protected:
	int value;
public:
	 bool_true()
	{
		value = true;
	}

};

class bool_false : public bool_literal
{
protected:
	int value;
public:
	 bool_false()
	{
		value = false;
	}

};
