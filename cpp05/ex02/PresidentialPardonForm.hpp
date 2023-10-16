/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:41:10 by abettini          #+#    #+#             */
/*   Updated: 2023/10/11 09:38:18 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		PresidentialPardonForm(const std::string target);

		virtual void	execute(Bureaucrat const & executor) const;
};

#endif
