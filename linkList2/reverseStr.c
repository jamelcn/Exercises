Reverse(char * String)
{
    int i = 0;
    char temp;
    int k = strlen(string) - 1;
    while(i && i < k)
    {
	temp = string[i];
	string[i] = string[k];
	string[k] = temp;
	i++;
	k--;
    }
}
