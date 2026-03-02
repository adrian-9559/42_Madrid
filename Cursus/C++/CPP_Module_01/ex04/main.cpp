/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:51:05 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/02 16:51:05 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 (search string) must not be empty\n";
		return (1);
	}

	std::ifstream ifs(filename.c_str());
	if (!ifs)
	{
		std::cerr << "Error: could not open input file '" << filename << "'\n";
		return (1);
	}

	std::ostringstream buf;
	buf << ifs.rdbuf();
	std::string content = buf.str();
	ifs.close();

	std::string outname = filename + ".replace";
	std::ofstream ofs(outname.c_str());
	if (!ofs)
	{
		std::cerr << "Error: could not create output file '" << outname << "'\n";
		return (1);
	}

	size_t pos = 0;
	while (pos < content.size())
	{
		size_t found = content.find(s1, pos);
		if (found == std::string::npos)
		{
			ofs << content.substr(pos);
			break;
		}
		ofs << content.substr(pos, found - pos);
		ofs << s2;
		pos = found + s1.length();
	}

	ofs.close();
	return (0);
}
