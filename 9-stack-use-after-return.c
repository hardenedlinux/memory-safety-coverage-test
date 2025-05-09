int *ptr;

void FunctionThatEscapesLocalObject() {
	int local[100];
	ptr = &local[0];
}

int main()
{
	FunctionThatEscapesLocalObject();
	*ptr = 1;

	return 0;
}
