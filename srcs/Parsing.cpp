//
// Parsing.cpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Fri Jun 12 14:57:29 2015 rousse_3
// Last update Tue Jul  7 21:41:54 2015 rousse_3
//

#include	"Parsing.hpp"

bool		isBlank(char c)
{
  if (c == ' ' || c == '\t')
    return (true);
  else
    return (false);
}

bool		isAlpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (true);
  else if (c >= 'A' && c <= 'Z')
    return (true);
  else
    return (false);
}

bool		isDigit(char c)
{
  if (c >= '0' && c <= '9')
    return (true);
  else
    return (false);
}

bool		isAlphaNum(char c)
{
  if (isAlpha(c))
    return (true);
  else if (isDigit(c))
    return (true);
  else if (c == '_')
    return (true);
  else
    return (false);
}

bool		isLineEmpty(const std::string &str)
{
  int		idx_str = 0;

  while (isBlank(str[idx_str]) == true)
    idx_str++;
  if (str[idx_str] == '\0')
    return (true);
  else
    return (false);
}
