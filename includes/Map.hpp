//
// Map.hpp for Pokemon in /home/rousse_3/Perso/CpPokemon
// 
// Made by rousse_3
// Login   <rousse_3@epitech.net>
// 
// Started on  Thu Jun 11 21:08:12 2015 rousse_3
// Last update Thu Jul  9 18:01:43 2015 rousse_3
//

#ifndef					MAP_HPP_
# define				MAP_HPP_

# include				<string>
# include				<vector>

class					Map
{
public:
  Map(void);
  Map(const std::string &filename);
  Map(const Map &copy);
  ~Map(void) throw();

  Map					&operator=(const Map &copy);
private:
  bool					getSize(const std::string &buffer, std::string &error);

  /*
  ** For debug
  */
  void					showMap(void) const;
  
  typedef	std::vector<int>	line;
	
  unsigned int				_sizeX;
  unsigned int				_sizeY;
  std::vector<line>			_map;
};

// TEST

int					testMap(void);

#endif					/* !MAP_HPP_ */
