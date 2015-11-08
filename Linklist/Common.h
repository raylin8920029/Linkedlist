#ifndef _COMMON_H_
#define _COMMON_H_

template<typename T>
inline void callWithMax(const T& a, const T& b)
{
	if (a > b)
	{
		printf("Bigger!!\n");
	}
	else
	{
		printf("Smeller!!\n");
	}
}

#endif // _COMMON_H_