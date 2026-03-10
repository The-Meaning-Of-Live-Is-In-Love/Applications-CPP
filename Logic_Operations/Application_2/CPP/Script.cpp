#include <iostream>
using namespace std;
class T_Log_Element
{
private:
	bool F_In_Value_1, F_In_Value_2;
protected:
	bool F_Result;
	virtual void Calculation() = 0;
	bool Get_In_Value_2()
	{
		return F_In_Value_2;
	}
	void Set_In_Value_2(bool New_In_Value_2);
	public:
		void Set_In_Value_1(bool New_In_Value_1);
		bool Get_Result()
		{
			return F_Result;
		}
		bool Get_In_Value_1()
		{
			return F_In_Value_1;
		}
};
void T_Log_Element::Set_In_Value_1(bool New_In_Value_1)
{
	F_In_Value_1 = New_In_Value_1;
	Calculation();
}
void T_Log_Element::Set_In_Value_2(bool New_In_Value_2)
{
	F_In_Value_2 = New_In_Value_2;
	Calculation();
}
class T_Log_In_Value_2 : public T_Log_Element
{
public:
	using T_Log_Element::Set_In_Value_2;
	using T_Log_Element::Get_In_Value_2;
};
class T_And: public T_Log_In_Value_2
{
	protected:
		void Calculation();
};
void T_And::Calculation()
{
	F_Result = Get_In_Value_1() && Get_In_Value_2();
}
class T_Or: public T_Log_In_Value_2
{
	protected:
		void Calculation();
};
void T_Or::Calculation()
{
	F_Result = Get_In_Value_1() || Get_In_Value_2();
}
class T_Implication: public T_Log_In_Value_2
{
	protected:
		void Calculation();
};
void T_Implication::Calculation()
{
	F_Result = !Get_In_Value_1() || Get_In_Value_2();
}
class T_Equivalence: public T_Log_In_Value_2
{
	protected:
		void Calculation();
};
void T_Equivalence::Calculation()
{
	F_Result = (Get_In_Value_1() && Get_In_Value_2()) || (!Get_In_Value_1() && !Get_In_Value_2());
}
int main()
{
	int Value_1, Value_2, Value_3;
	T_Implication elImplication;
	T_Equivalence elEquivalence;
	cout << u8"X	Y	Z	X → Y	X → Y ↔ Z" << '\n';
	for (Value_1 = 0; Value_1 <= 1; Value_1++)
	{
		elImplication.Set_In_Value_1(Value_1);
		for (Value_2 = 0; Value_2 <= 1; Value_2++)
		{
			elImplication.Set_In_Value_2(Value_2);
			for (Value_3 = 0; Value_3 <= 1; Value_3++)
			{
				elEquivalence.Set_In_Value_1(elImplication.Get_Result());
				elEquivalence.Set_In_Value_2(Value_3);
				cout << Value_1 << '\t' << Value_2 << '\t' << Value_3 << '\t' << elImplication.Get_Result() << '\t' << elEquivalence.Get_Result() << '\n';
			}
		}
	}
	return 0;
}

