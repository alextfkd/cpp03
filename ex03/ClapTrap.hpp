/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 06:13:44 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 06:24:55 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <limits>
#include <string>

class ClapTrap {
 private:
  const static unsigned int kDefaultHitPoints     = 10;
  const static unsigned int kDefaultEnPoints      = 10;
  const static unsigned int kDefaultAttackDamages = 0;

 protected:
  std::string  type_;
  std::string  name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;

  bool checkHitPoints();
  bool useEnergyPoints();

 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  virtual ~ClapTrap();

  virtual void attack(const std::string& target);
  void         takeDamage(unsigned int amount);
  void         beRepaired(unsigned int amount);
  void         showStatus(void) const;
  std::string  getName(void) const;
};

#endif
