//
// Error.hpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jul  9 16:26:44 2015 rousse_3
// Last update Thu Jul  9 16:35:53 2015 rousse_3
//

#include	"Error.hpp"

PokemonError::PokemonError(const std::string &what, const std::string &where) :
  _what(what),
  _where(where)
{}

PokemonError::~PokemonError(void) throw()
{}

const char			*PokemonError::what(void) const throw()
{
  return (_what.c_str());
}

const char			*PokemonError::where(void) const throw()
{
  return (_where.c_str());
}

ParsingError::ParsingError(const std::string &what, const std::string &where) :
  std::runtime_error(what),
  PokemonError(what, where)
{}

ParsingError::~ParsingError(void) throw()
{}

const char			*ParsingError::what(void) const throw()
{
  return (PokemonError::what());
}

const char			*ParsingError::where(void) const throw()
{
  return (PokemonError::where());
}
