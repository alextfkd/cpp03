/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:29:08 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 16:06:43 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap claptrap_a = ClapTrap("alpha");
  ClapTrap claptrap_b = ClapTrap("bravo");
  ClapTrap claptrap_c = ClapTrap("charlie");

  std::cout << "Attack test. Alpha cannot attack if it has no energy."
            << std::endl
            << std::endl;
  for (int idx = 0; idx < 12; idx++) {  // NOLINT
    claptrap_a.showStatus();
    claptrap_a.attack(claptrap_b.getName());
  }

  std::cout << std::endl
            << "Attack test. Bravo cannot attack if it has no hit points."
            << std::endl
            << std::endl;
  for (int idx = 0; idx < 7; idx++) {  // NOLINT
    claptrap_b.showStatus();
    claptrap_b.attack(claptrap_b.getName());
    claptrap_b.takeDamage(2);
  }

  std::cout << std::endl
            << "BeRepaired test. Overflow is safely covered." << std::endl
            << std::endl;
  for (int idx = 0; idx < 3; idx++) {
    claptrap_c.showStatus();
    claptrap_c.beRepaired(0xFFFFFFFA);  // NOLINT
  }
  return 0;
}
