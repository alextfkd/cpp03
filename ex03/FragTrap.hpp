/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:12:53 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/25 09:23:17 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 protected:
  const static unsigned int kDefaultHitPoints_     = 100;
  const static unsigned int kDefaultEnPoints_      = 100;
  const static unsigned int kDefaultAttackDamages_ = 30;

 public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  ~FragTrap();

  void highFivesGuys(void);
};

#endif
