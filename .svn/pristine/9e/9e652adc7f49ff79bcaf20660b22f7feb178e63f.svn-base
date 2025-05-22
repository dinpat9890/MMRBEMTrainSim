/// @file IndividualObjectCallbacks.h
/// Helper callbacks for traversing the Comms data heirarchy.
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "SimComms/Object.h"
#include "Utility/Utilities.h"

namespace Sim
{
    namespace Project
    {
        /// A callback function that provides filtering based on class ID.
        ///
        /// @tparam ObjectClassID An object class ID e.g Core::ClassId::WORLD.
        template <int ObjectClassID>
        class ClassIs
        {
        public:
            /// Constructs a function object that is intended to form part of a
            /// callback chain. This object essentially filters on class ID.
            ///
            /// @param next_callback
            ///        Called if the class ID of the object matches the template
            ///        parameter.
            ///
            /// @note If next_callback is called, it is guaranteed that the object
            ///       is valid, and has a class ID matching the template
            ///       parameter.
            ClassIs(Comms::IndividualObjectCallback next_callback)
              : m_next_callback(next_callback) { }

            /// @internal
            /// This makes the object conform to the requirements for a
            /// Comms::IndividualObjectCallback.
            void operator()(Comms::Object object)
            {
                if(object.IsValid())
                {
                    if(Core::GetClassID(object) == ObjectClassID)
                        m_next_callback(object);
                }
            }

        private:
            Comms::IndividualObjectCallback m_next_callback;
        };

        /// A callback function that adds a child creation callback depending
        /// upon an object's class ID.
        ///
        /// @tparam ObjectClassID An object class ID e.g Core::ClassId::WORLD.
        template <int ObjectClassID>
        class ChildrenOfClass
        {
        public:
            /// Constructs a function object that is intended to form part of a
            /// callback chain. The next callback is called when children are
            /// created, for a parent object of a specific class.
            ///
            /// @param next_callback
            ///        Attached to the incoming object as a child creation
            ///        listener, and subsequently called on creation.
            ///
            /// @note Unlike ClassIs<>, this does not provide any guarantees
            ///       on the state of the object passed to next_callback.
            ChildrenOfClass(Comms::IndividualObjectCallback next_callback)
              : m_next_callback(next_callback) { }

            /// @internal
            /// This makes the object conform to the requirements for a
            /// Comms::IndividualObjectCallback.
            void operator()(Comms::Object object)
            {
                if(object.IsValid())
                {
                    if(Core::GetClassID(object) == ObjectClassID)
                        Comms::AddCreationCallback(object, m_next_callback);
                }
            }

        private:
            Comms::IndividualObjectCallback m_next_callback;
        };

        /// An object callback function that provides filtering based on a Tag.
        class TagIs
        {
        public:
            /// Constructs a function object that is intended to form part of a
            /// callback chain. This object essentially filters on a Tag.
            ///
            /// @param tag
            ///        The tag to filter on.
            /// @param next_callback
            ///        Called if an object has the given Tag.
            ///
            /// @note If next_callback is called, it is guaranteed that the object
            ///       is valid, and has the specified tag.
            TagIs(const std::string &tag, Comms::IndividualObjectCallback next_callback)
              : m_tag(tag), m_next_callback(next_callback) { }

            /// @internal
            /// This makes the object conform to the requirements for a
            /// Comms::IndividualObjectCallback.
            void operator()(Comms::Object object)
            {
                if(object.IsValid())
                {
                    if(object.Statics().Tags().Exists(m_tag))
                        m_next_callback(object);
                }
            }

        private:
            std::string                     m_tag;
            Comms::IndividualObjectCallback m_next_callback;
        };

        /// An object callback function that adds a child creation callback
        /// depending upon the existence of a Tag.
        class ChildrenOfTag
        {
        public:
            /// Constructs a function object that is intended to form part of a
            /// callback chain. The next callback is called when children are
            /// created, for a parent object with a specific Tag.
            ///
            /// @param tag
            ///        The Tag present on the parent object.
            /// @param next_callback
            ///        Attached to the incoming object as a child creation
            ///        listener, if the incoming object has the Tag specified
            ///        by the previous parameter.
            ///
            /// @note Unlike TagIs, this does not provide any guarantees
            ///       on the state of the object passed to next_callback.
            ChildrenOfTag(const std::string &tag, Comms::IndividualObjectCallback next_callback)
              : m_tag(tag), m_next_callback(next_callback) { }

            /// @internal
            /// This makes the object conform to the requirements for a
            /// Comms::IndividualObjectCallback.
            void operator()(Comms::Object object)
            {
                if(object.IsValid())
                {
                    if(object.Statics().Tags().Exists(m_tag))
                        Comms::AddCreationCallback(object, m_next_callback);
                }
            }

        private:
            std::string                     m_tag;
            Comms::IndividualObjectCallback m_next_callback;
        };

        typedef std::function<bool (const Comms::Object &)> CommsObjectPredicate;

        inline CommsObjectPredicate operator&&(const CommsObjectPredicate &a, const CommsObjectPredicate &b)
        {
            return [a, b](const Comms::Object &object) { return a(object) && b(object); };
        }

        inline CommsObjectPredicate operator||(const CommsObjectPredicate &a, const CommsObjectPredicate &b)
        {
            return [a, b](const Comms::Object &object) { return a(object) || b(object); };
        }

        /// An object callback function that adds a child creation callback
        /// depending upon a generic predicate.
        class ChildrenOf
        {
        public:
            /// Constructs a function object that is intended to form part of a
            /// callback chain. The next callback is called for children of an
            /// object that meets the conditions of some generic predicate
            /// function.
            ///
            /// @param predicate
            ///        The predicate function.
            /// @param next_callback
            ///        Attached to the incoming object as a child creation
            ///        listener, if the incoming object meets the conditions
            ///        of the predicate.
            ///
            /// @note This does not provide any guarantees on the state of the
            ///       object passed to next_callback.
            ChildrenOf(CommsObjectPredicate            predicate,
                       Comms::IndividualObjectCallback next_callback)
              : m_predicate(predicate), m_next_callback(next_callback) { }

            /// @internal
            /// This makes the object conform to the requirements for a
            /// Comms::IndividualObjectCallback.
            void operator()(Comms::Object object)
            {
                if(object.IsValid())
                {
                    if(m_predicate(object))
                        Comms::AddCreationCallback(object, m_next_callback);
                }
            }

        private:
            CommsObjectPredicate            m_predicate;
            Comms::IndividualObjectCallback m_next_callback;
        };
    }
}
