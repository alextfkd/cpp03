/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:29:08 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 03:12:58 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void constructorTest() {
  typedef FragTrap t;
  std::string      type = "FragTrap";
  std::cout << "=== Constructor Test Start ===" << std::endl;
  std::cout << "=== 1. Default Constructor Test ===" << std::endl;
  t instance_0;
  std::cout << type << " 0 name: " << instance_0.getName() << std::endl;

  std::cout << "\n=== 2. Parameter Constructor Test ===" << std::endl;
  t const instance_1("Uno");
  t const instance_2("Dos");
  std::cout << type << " 1 name: " << instance_1.getName() << std::endl;
  std::cout << type << " 2 name: " << instance_2.getName() << std::endl;

  std::cout << "\n=== 3. Copy Constructor Test ===" << std::endl;
  t instance_2copy(instance_2);  // NOLINT
  std::cout << type << " 2 (copy) name: " << instance_2copy.getName()
            << std::endl;

  std::cout << "\n=== 4. Copy Assignment Operator Test ===" << std::endl;
  t const instance_3("Tres");
  t       instance_3copyassigned;
  instance_3copyassigned = instance_3;
  std::cout << type << " 3 name: " << instance_3.getName() << std::endl;
  std::cout << type
            << " 3 (copy-assigned) name: " << instance_3copyassigned.getName()
            << std::endl;
  std::cout << "=== Constructor Test  End ===" << std::endl << std::endl;
}

int main(void) {
  constructorTest();
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
