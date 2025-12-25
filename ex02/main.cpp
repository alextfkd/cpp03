/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:29:08 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 07:06:54 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap claptrap_a = ClapTrap("alpha");
  ScavTrap scavtrap_b = ScavTrap("bravo");
  FragTrap fragtrap_c = FragTrap("charlie");
  std::cout << std::endl;

  std::cout << "ClapTrap Attack test. Alpha cannot attack if it has no energy."
            << std::endl
            << std::endl;
  for (int idx = 0; idx < 12; idx++) {  // NOLINT
    claptrap_a.showStatus();
    claptrap_a.attack(scavtrap_b.getName());
  }

  std::cout
      << std::endl
      << "FragTrap Attack test. Charlie cannot attack if it has no hit points."
      << std::endl
      << std::endl;
  for (int idx = 0; idx < 7; idx++) {  // NOLINT
    fragtrap_c.showStatus();
    fragtrap_c.attack(scavtrap_b.getName());
    fragtrap_c.highFivesGuys();
    fragtrap_c.takeDamage(24);  // NOLINT
  }
  std::cout << std::endl;
  return 0;
}
