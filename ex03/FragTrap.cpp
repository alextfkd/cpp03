/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:12:51 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/28 03:05:37 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include "ClapTrap.hpp"

FragTrap::FragTrap() {
  this->type_          = "FragTrap";
  this->hit_points_    = FragTrap::kDefaultHitPoints;
  this->energy_points_ = FragTrap::kDefaultEnPoints;
  this->attack_damage_ = FragTrap::kDefaultAttackDamages;
  std::cout << this->getName() << " constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  this->type_          = "FragTrap";
  this->hit_points_    = FragTrap::kDefaultHitPoints;
  this->energy_points_ = FragTrap::kDefaultEnPoints;
  this->attack_damage_ = FragTrap::kDefaultAttackDamages;
  std::cout << this->getName() << " parameter constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << this->getName() << " copy constructor called." << std::endl;
  *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << this->getName() << " copy assignment constructor called."
            << std::endl;
  if (this != &other) {
    this->type_          = other.type_;
    this->name_          = other.name_;
    this->hit_points_    = other.hit_points_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_points_ = other.energy_points_;
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << this->getName() << " destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
  if (!this->checkHitPoints()) {
    return;
  }
  if (!this->useEnergyPoints()) {
    return;
  }
  std::cout << this->getName() << " says 'Guys!! Give me high-five!!!'."
            << std::endl;
}
