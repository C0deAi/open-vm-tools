/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/CafCoreTypesXml/FullyQualifiedClassGroupXml.h"

#include "Doc/CafCoreTypesDoc/CFullyQualifiedClassGroupDoc.h"
#include "Doc/ProviderInfraDoc/CClassCollectionDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/ProviderInfraXml/ClassCollectionXml.h"

using namespace Caf;

void ClassCollectionXml::add(
	const SmartPtrCClassCollectionDoc classCollectionDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ClassCollectionXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(classCollectionDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::deque<SmartPtrCFullyQualifiedClassGroupDoc> fullyQualifiedClassVal =
			classCollectionDoc->getFullyQualifiedClass();
		CAF_CM_VALIDATE_STL(fullyQualifiedClassVal);

		if (! fullyQualifiedClassVal.empty()) {
			for (TConstIterator<std::deque<SmartPtrCFullyQualifiedClassGroupDoc> > fullyQualifiedClassIter(fullyQualifiedClassVal);
				fullyQualifiedClassIter; fullyQualifiedClassIter++) {
				const SmartPtrCXmlElement fullyQualifiedClassXml =
					thisXml->createAndAddElement("fullyQualifiedClass");
				FullyQualifiedClassGroupXml::add(*fullyQualifiedClassIter, fullyQualifiedClassXml);
			}
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCClassCollectionDoc ClassCollectionXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ClassCollectionXml", "parse");

	SmartPtrCClassCollectionDoc classCollectionDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const CXmlElement::SmartPtrCElementCollection fullyQualifiedClassChildrenXml =
			thisXml->findRequiredChildren("fullyQualifiedClass");

		std::deque<SmartPtrCFullyQualifiedClassGroupDoc> fullyQualifiedClassVal;
		if (! fullyQualifiedClassChildrenXml.IsNull() && ! fullyQualifiedClassChildrenXml->empty()) {
			for (TConstIterator<CXmlElement::CElementCollection> fullyQualifiedClassXmlIter(*fullyQualifiedClassChildrenXml);
				fullyQualifiedClassXmlIter; fullyQualifiedClassXmlIter++) {
				const SmartPtrCXmlElement fullyQualifiedClassXml = fullyQualifiedClassXmlIter->second;
				const SmartPtrCFullyQualifiedClassGroupDoc fullyQualifiedClassDoc =
					FullyQualifiedClassGroupXml::parse(fullyQualifiedClassXml);
				fullyQualifiedClassVal.push_back(fullyQualifiedClassDoc);
			}
		}

		classCollectionDoc.CreateInstance();
		classCollectionDoc->initialize(
			fullyQualifiedClassVal);
	}
	CAF_CM_EXIT;

	return classCollectionDoc;
}

