/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:53:35 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:53:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN
{
  private:
	std::stack<int> _stack;

  public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	void pushNumber(const int num);
	int compute(const char op);
	int top() const;
	bool empty() const;
	int size() const;
	~RPN();
};

#endif
