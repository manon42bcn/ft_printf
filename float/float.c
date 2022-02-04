int	ft_print_double(double nbr, t_token *token)
{
	long int	whole;
	long int	decimals;
	int			rst;
	t_token		*ratio;	

	whole = (long int)nbr;
	nbr = nbr - whole;
	decimals = nbr * ft_power_ten(token->precision + 1);
	if ((decimals % 10) >= 5)
		decimals = (decimals / 10) + 1;
	else
		decimals = decimals / 10;
	rst = 0;
	token->width = token->width - token->precision - 1;
	rst += ft_print_int(whole, token);
	rst += write(1, ".", 1);
	ratio = ft_start_token();
	ratio->width = token->precision;
	ratio->fill_c = '0';
	rst += ft_print_int(decimals, ratio);
	free(ratio);
	return (rst);
}

unsigned int	ft_power_ten(int n)
{
	unsigned int	rst;

	rst = 1;
	while (n-- > 0)
		rst = rst * 10;
	return (rst);
}
