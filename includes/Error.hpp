//
// Error.hpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jul  9 16:21:55 2015 rousse_3
// Last update Thu Jul  9 16:35:19 2015 rousse_3
//

#ifndef				ERROR_HPP_
# define			ERROR_HPP_

# include			<string>
# include			<stdexcept>

class				PokemonError
{
public:
  PokemonError(const std::string &what, const std::string &where = "");
  virtual ~PokemonError(void) throw();

  virtual const char			*what(void) const throw();
  virtual const char			*where(void) const throw();
protected:
  std::string			_what;
  std::string			_where;
};

class				ParsingError : public std::runtime_error, public PokemonError
{
public:
  ParsingError(const std::string &what, const std::string &where = "");
  ~ParsingError(void) throw();

  virtual const char			*what(void) const throw();
  virtual const char			*where(void) const throw();
};

#endif
