

static void	skip_whitespace_and_sign(char **s, double *sign)
{
	while (**s == ' ' || (**s >= 9 && **s <= 13))
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1.0;
		(*s)++;
	}
}

static double	parse_integer_part(char **s)
{
	double	res;

	res = 0.0;
	while (**s >= '0' && **s <= '9')
		res = res * 10.0 + (*((*s)++) - '0');
	return (res);
}

static double	parse_fractional_part(char **s)
{
	double	frac;
	double	div;

	frac = 0.0;
	div = 1.0;
	if (**s == '.')
	{
		(*s)++;
		while (**s >= '0' && **s <= '9')
		{
			frac = frac * 10.0 + (*((*s)++) - '0');
			div *= 10.0;
		}
	}
	return (frac / div);
}

double	ft_atod(char *s)
{
	double	sign;
	double	res;
	double	frac;

	sign = 1.0;
	skip_whitespace_and_sign(&s, &sign);
	res = parse_integer_part(&s);
	frac = parse_fractional_part(&s);
	return ((res + frac) * sign);
}