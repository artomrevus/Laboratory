#ifndef table_ptr_h
#define table_ptr_h

void for_table(double a, double b, double h);
void while_table(double a, double b, double h);
void do_while_table(double a, double b, double h);
void error_table(double a, double b, double h);
void table_method(double a, double b, double h, void (*pTable_1)(double, double, double));

#endif
