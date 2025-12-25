/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 06:13:44 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 03:57:33 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <limits>
#include <string>

class ClapTrap {
 private:
  const static unsigned int kDefaultHitPoints_     = 10;
  const static unsigned int kDefaultEnPoints_      = 10;
  const static unsigned int kDefaultAttackDamages_ = 0;
  const static unsigned int kUINT_MAX_             = (unsigned int)0xFFFFFFFF;

  const std::string kType_;

  std::string  name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;

  bool checkHitPoints_();
  bool useEnergyPoints_();

 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  ~ClapTrap();

  void        attack(const std::string& target);
  void        takeDamage(unsigned int amount);
  void        beRepaired(unsigned int amount);
  void        showStatus(void) const;
  std::string getName(void) const;
};

#endif
