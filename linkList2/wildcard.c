// 所谓通用字符串，比如用"*"表示可以匹配任何长度的字符串，而'?'用来匹配一个任意字符。
bool Match(char * Source, char * Mode)
{
    while(*Mode != NULL)
    {
	if(*Mode == '*')
	{
	    Mode ++;
	    while(*Mode != *Source)
	    {
		Source ++;
		if(*Source == NULL && *Mode != NULL)
		    return false;
	    }
	    Continue;
	}

	if(*Source == NULL)
	    return false;

	if(*Mode == '?')
	{
	    Mode ++;
	    Source ++;
	    continue;
	}
	if(*Source != *Mode)
	{
	    while(*Mode != '*' && *Mode != NULL)
	    {
		Source --;
		Mode --;
	    }
	    if(*Mode == NULL)
	    {
		return false;
	    }
	    Source += 2;
	    continue;
	}
	else
	{
	    Mode ++;
	    Source++;
	    Continue;
	}
    }
    if(*Source == NULL)
	return true;
}
