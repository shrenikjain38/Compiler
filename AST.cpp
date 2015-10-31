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
	location::location(int locs)
	{
		loc = locs;
	}

	int location::evaluate()
	{
		return loc;
	}
	

};

class unary_minus:public expr
{
protected:
	expr *expression;
public:
	unary_minus::unary_minus(expr* express)
	{
		expression = express;
	}
	int unary_minus::evaluate()
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
	unary_not::unary_not(expr* express)
	{
		expression = express;
	}
	int unary_not::evaluate()
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
	plus::plus(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int plus::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left + right;
		return num;
	}

};

class minus:public expr
{
protected:
	expr *left;
	expr *right;
public:
	plus::minus(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int minus::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left - right;
		return num;
	}

};

class multiply:public expr
{
protected:
	expr *left;
	expr *right;
public:
	multiply::multiply(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int multiply::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left * right;
		return num;
	}

};

class divide:public expr
{
protected:
	expr *left;
	expr *right;
public:
	divide::divide(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int divide::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left / right;
		return num;
	}

};

class modulo:public expr
{
protected:
	expr *left;
	expr *right;
public:
	modulo::modulo(expr *l, expr *r)
	{
		left = l;
		right = r;
	}

	int modulo::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left % right;
		return num;
	}

};

class rel_op : public expr
{
protected:
	expr *left;
	expr *right;
public:
	rel_op :: rel_op(expr *l, expr *r)
	{
		left = l;
		right = r;
	}	

};

class less_than :: public rel_op
{
public:
	less_than::less_than()
	{}

	int less_than::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right_num->evaluate();
		num = left_num < right_num;
		return num;
	}


};

class less_equal :: public rel_op
{
	public:
	less_equal::less_equal()
	{}

	int less_equal::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right_num->evaluate();
		num = left_num <= right_num;
		return num;
	}


};

class greater_than :: public rel_op
{
	public:
	greater_than::greater_than()
	{}

	int greater_than::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right_num->evaluate();
		num = left_num < right_num;
		return num;
	}
};

class greater_equal :: public rel_op
{
public:
	greater_equal::greater_equal()
	{}

	int greater_equal::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right_num->evaluate();
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
	eq_op::eq_op(expr *l, expr *r)
	{
		left = l;
		right = r;
	}	
};

class equal_equal : public expr
{
public:
	equal_equal::equal_equal()
	{}

	int equal_equal::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num == right_num;
	}
};

class not_equal : public expr
{
public:
	not_equal::not_equal()
	{}

	int not_equal::evaluate()
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
	cond_op :: cond_op(expr *l, expr *r)
	{
		left = l;
		right = r;
	}	

};

class and:public cond_op
{
public:
	and::and()
	{}

	and::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num && right_num;

	}

};

class or:public cond_op
{
public:
	or::or()
	{}

	or::evaluate()
	{
		int left_num,right_num;
		left_num = left->evaluate();
		right_num = right->evaluate();
		num = left_num || right_num;

	}

};


class int_value : public int_literal
{
protected:
	int num;
public:
	int_value :: int_value(int value)
	{
		num = value;
	}
};

class char_value : public char_literal
{
protected:
	char character;
public:
	char_value :: char_value(char value)
	{
		character = value;
	}

};

class bool_true : public bool_literal
{
protected:
	int value;
public:
	bool_true :: bool_true()
	{
		value = true;
	}

};

class bool_false : public bool_literal
{
protected:
	int value;
public:
	bool_false :: bool_false()
	{
		value = false;
	}

};