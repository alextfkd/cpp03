/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:29:08 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 00:50:09 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void constructorTest() {
  typedef ClapTrap t;
  std::string      type = "CrapTrap";
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
            << std::endl
            << std::endl;
  std::cout << "\n=== 5. Destructor Test ===" << std::endl;
}

int main(void) {
  constructorTest();
  std::cout << std::endl;
  std::cout << "=== Functional Test Start ===" << std::endl;
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
  std::cout << "=== Functional Test End ===" << std::endl;
  return 0;
}
