/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:12:53 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 06:56:12 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  const static unsigned int kDefaultHitPoints_     = 100;
  const static unsigned int kDefaultEnPoints_      = 50;
  const static unsigned int kDefaultAttackDamages_ = 20;

 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  ~ScavTrap();

  void attack(const std::string& target);
  void guardGate(void);
};

#endif
