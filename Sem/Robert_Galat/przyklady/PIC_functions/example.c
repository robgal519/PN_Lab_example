extern int foo2(int);
int main(){
	foo3();
	printf("%p",&foo2);
	foo3();
	return 0;
}
