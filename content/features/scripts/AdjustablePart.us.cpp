///
/// @file       AdjustablePart.us.cpp
///
/// @ingroup    95809A9A
///
/// @author     Andy Cooper
///
/// @copyright  SYDAC Pty Ltd, 2015
///

#ifndef ADJUSTABLE_PART_US_CPP
#define ADJUSTABLE_PART_US_CPP

#include <features/SwitchablePartFeature.us.cpp>
#include <Utilities.us.cpp>

namespace ProjUtil
{
    
	/// @brief Represents a feature part that may be adjusted horizontally or vertically.
	/// Note that the Adjustable Part must be an immediate child of the Top Level Parent Node
	class AdjustablePart
	{
		
	private:
		Node                    m_node              = 0;             ///< The Node representing this part.
		Features::NodeWrapper   m_node_wrapper      = 0;             ///< The NodeWrapper representing this part.
		Mat4                    m_initial_transform = Mat4_identity; ///< The initial transform, to which adjustments will be applied.
		double                  m_horizontal_offset = 0.0;           ///< Distance to move the part horizontally.
		double                  m_vertical_offset   = 0.0;           ///< Distance to move the part vertically.
		double                  m_lateral_offset    = 0.0;           ///< Distance to move the part towards-away from.
		string                  m_part_name;                         ///< Name of the node representing this part.
		Features::SwitchablePartFeature m_feature;

		/// @brief Applies the vertical and horizontal offsets to the node.
		void apply()
		{
			// If we haven't already, attempt to find the node representing this part.
			if(m_node == 0)
			{
				if (m_feature == 0)
				{
					log.error("%s (line %d): AdjustablePart::apply() - Invalid SwitchablePartFeature supplied for part \"%s\"", __FILE__, __LINE__, m_part_name);
					return;
				}
				
				m_node_wrapper = m_feature.getNode();
				if(m_node_wrapper == 0)
				{
					log.error("%s (line %d): AdjustablePart::apply() - Invalid NodeWrapper supplied for part \"%s\" Feature %s ID %d", __FILE__, __LINE__, m_part_name, m_feature.getName(), m_feature.getID());
					return;
				}

				Node parent = m_node_wrapper.getNode(0);
				if(parent == 0)
				{
					log.error("%s (line %d): AdjustablePart::apply() - NodeWrapper is empty for part \"%s\" Feature %s ID %d", __FILE__, __LINE__, m_part_name, m_feature.getName(), m_feature.getID());
					return;
				}
				
				m_node = findPathNode( parent, m_part_name);
				
				if (m_node == 0)
		        {
					log.error("%s (line %d): AdjustablePart::apply() - Unable to find child part \"%s\" Feature %s ID %d", __FILE__, __LINE__, m_part_name, m_feature.getName(), m_feature.getID());
					return;
				}

				//int CHILD_ID = parent.findChild(m_part_name);
				//if(CHILD_ID == -1)
				//{
				//	log.error("%s (line %d): AdjustablePart::apply() - Unable to find child part \"%s\" Feature %s ID %d", __FILE__, __LINE__, m_part_name, m_feature.getName(), m_feature.getID());
				//	return;
				//}

				//m_node              = parent.getChild(CHILD_ID);
				m_initial_transform = m_node.getTransform();
			}
				
			// Realistically, we shouldn't have a null m_node at this point unless parent.getChild(CHILD_ID)
			// (above) returned one to us. Which would be all kinds of bad... Let's be defensive anyway.
			if(m_node != 0)
				m_node.setTransform(translate(m_horizontal_offset, m_lateral_offset, m_vertical_offset) * m_initial_transform);
			else
				log.error("%s (line %d): AdjustablePart::apply() - Somehow we have no node representing part \"%s\"  Feature %s ID %d, when we really should have.", __FILE__, __LINE__, m_part_name, m_feature.getName(), m_feature.getID());
		}

	public:
		/// @brief Creates a new part that may be moved horizontally and/or vertically.
		///
		/// @param PART_NAME
		///        Name of the child node that represents this part.
		AdjustablePart(Features::SwitchablePartFeature feature, string PART_NAME)
		{
			// We will defer finding this part until later. Because all the
			// parts are optional, there's no point complaining about them
			// missing until somebody actually wants to do something with them.
			m_part_name = PART_NAME;
			m_feature = feature;
			
		}

		/// @brief Adjusts the part horizontally.
		/// @param VALUE
		///        Distance to move the part horizontally (i.e. along its local X axis). This is always
		///        relative to the original location of the part, and is not cumulative.
		void setHorizontalOffset(double VALUE)
		{
			m_horizontal_offset = VALUE;
			apply();
		}

		/// @brief Adjusts the part vertically.
		/// @param VALUE
		///        Distance to move the part vertically (i.e. along its local Z axis). This is always
		///        relative to the original location of the part, and is not cumulative.
		void setVerticalOffset(double VALUE)
		{
			m_vertical_offset = VALUE;
			apply();
		}
		
		/// @brief Adjusts the part vertically.
		/// @param VALUE
		///        Distance to move the part laterally (i.e. along its local Y axis). This is always
		///        relative to the original location of the part, and is not cumulative.
		void setLateralOffset(double VALUE)
		{
			m_lateral_offset = VALUE;
			apply();
		}
	};

} // namespace ADJUSTABLE_PART_US_CPP

#endif
