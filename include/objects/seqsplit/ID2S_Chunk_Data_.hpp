/* $Id$
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 */

/// @file ID2S_Chunk_Data_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqsplit.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQSPLIT_ID2S_CHUNK_DATA_BASE_HPP
#define OBJECTS_SEQSPLIT_ID2S_CHUNK_DATA_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CBioseq;
class CID2S_Sequence_Piece;
class CSeq_align;
class CSeq_annot;
class CSeq_descr;
class CSeq_id;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_ID2_EXPORT CID2S_Chunk_Data_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID2S_Chunk_Data_Base(void);
    // destructor
    virtual ~CID2S_Chunk_Data_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    /// place of data to insert
    class NCBI_ID2_EXPORT C_Id : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Id(void);
        // destructor
        ~C_Id(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
    
        /// Choice variants.
        enum E_Choice {
            e_not_set = 0,  ///< No variant selected
            e_Bioseq_set,   ///< Bioseq-set id
            e_Gi,           ///< Bioseq id
            e_Seq_id        ///< Bioseq id
        };
        /// Maximum+1 value of the choice variant enumerator.
        enum E_ChoiceStopper {
            e_MaxChoice = 4 ///< == e_Seq_id+1
        };
    
        /// Reset the whole object
        void Reset(void);
    
        /// Reset the selection (set it to e_not_set).
        void ResetSelection(void);
    
        /// Which variant is currently selected.
        E_Choice Which(void) const;
    
        /// Verify selection, throw exception if it differs from the expected.
        void CheckSelected(E_Choice index) const;
    
        /// Throw 'InvalidSelection' exception.
        NCBI_NORETURN void ThrowInvalidSelection(E_Choice index) const;
    
        /// Retrieve selection name (for diagnostic purposes).
        static string SelectionName(E_Choice index);
    
        /// Select the requested variant if needed.
        void Select(E_Choice index, EResetVariant reset = eDoResetVariant);
        /// Select the requested variant if needed,
        /// allocating CObject variants from memory pool.
        void Select(E_Choice index,
                    EResetVariant reset,
                    CObjectMemoryPool* pool);
    
        // types
        typedef int TBioseq_set;
        typedef int TGi;
        typedef CSeq_id TSeq_id;
    
        // getters
        // setters
    
        // typedef int TBioseq_set
        bool IsBioseq_set(void) const;
        TBioseq_set GetBioseq_set(void) const;
        TBioseq_set& SetBioseq_set(void);
        void SetBioseq_set(TBioseq_set value);
    
        // typedef int TGi
        bool IsGi(void) const;
        TGi GetGi(void) const;
        TGi& SetGi(void);
        void SetGi(TGi value);
    
        // typedef CSeq_id TSeq_id
        bool IsSeq_id(void) const;
        const TSeq_id& GetSeq_id(void) const;
        TSeq_id& SetSeq_id(void);
        void SetSeq_id(TSeq_id& value);
    
    
    private:
        // copy constructor and assignment operator
        C_Id(const C_Id& );
        C_Id& operator=(const C_Id& );
        // choice state
        E_Choice m_choice;
        // helper methods
        void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
    
        static const char* const sm_SelectionNames[];
        // data
        union {
            TBioseq_set m_Bioseq_set;
            TGi m_Gi;
            NCBI_NS_NCBI::CSerialObject *m_object;
        };
    };
    // types
    typedef C_Id TId;
    typedef CSeq_descr TDescr;
    typedef list< CRef< CSeq_annot > > TAnnots;
    typedef list< CRef< CSeq_align > > TAssembly;
    typedef list< CRef< CID2S_Sequence_Piece > > TSeq_map;
    typedef list< CRef< CID2S_Sequence_Piece > > TSeq_data;
    typedef list< CRef< CBioseq > > TBioseqs;

    // getters
    // setters

    /// mandatory
    /// typedef C_Id TId
    ///  Check whether the Id data member has been assigned a value.
    bool IsSetId(void) const;
    /// Check whether it is safe or not to call GetId method.
    bool CanGetId(void) const;
    void ResetId(void);
    const TId& GetId(void) const;
    void SetId(TId& value);
    TId& SetId(void);

    /// Seq-descr, for Bioseq and Bioseq-set
    /// optional
    /// typedef CSeq_descr TDescr
    ///  Check whether the Descr data member has been assigned a value.
    bool IsSetDescr(void) const;
    /// Check whether it is safe or not to call GetDescr method.
    bool CanGetDescr(void) const;
    void ResetDescr(void);
    const TDescr& GetDescr(void) const;
    void SetDescr(TDescr& value);
    TDescr& SetDescr(void);

    /// Seq-annot, for Bioseq and Bioseq-set
    /// optional
    /// typedef list< CRef< CSeq_annot > > TAnnots
    ///  Check whether the Annots data member has been assigned a value.
    bool IsSetAnnots(void) const;
    /// Check whether it is safe or not to call GetAnnots method.
    bool CanGetAnnots(void) const;
    void ResetAnnots(void);
    const TAnnots& GetAnnots(void) const;
    TAnnots& SetAnnots(void);

    /// assembly history Seq-align, for Bioseq
    /// optional
    /// typedef list< CRef< CSeq_align > > TAssembly
    ///  Check whether the Assembly data member has been assigned a value.
    bool IsSetAssembly(void) const;
    /// Check whether it is safe or not to call GetAssembly method.
    bool CanGetAssembly(void) const;
    void ResetAssembly(void);
    const TAssembly& GetAssembly(void) const;
    TAssembly& SetAssembly(void);

    /// sequence map, for Bioseq
    /// optional
    /// typedef list< CRef< CID2S_Sequence_Piece > > TSeq_map
    ///  Check whether the Seq_map data member has been assigned a value.
    bool IsSetSeq_map(void) const;
    /// Check whether it is safe or not to call GetSeq_map method.
    bool CanGetSeq_map(void) const;
    void ResetSeq_map(void);
    const TSeq_map& GetSeq_map(void) const;
    TSeq_map& SetSeq_map(void);

    /// sequence data, for Bioseq
    /// optional
    /// typedef list< CRef< CID2S_Sequence_Piece > > TSeq_data
    ///  Check whether the Seq_data data member has been assigned a value.
    bool IsSetSeq_data(void) const;
    /// Check whether it is safe or not to call GetSeq_data method.
    bool CanGetSeq_data(void) const;
    void ResetSeq_data(void);
    const TSeq_data& GetSeq_data(void) const;
    TSeq_data& SetSeq_data(void);

    /// Bioseq, for Bioseq-set
    /// optional
    /// typedef list< CRef< CBioseq > > TBioseqs
    ///  Check whether the Bioseqs data member has been assigned a value.
    bool IsSetBioseqs(void) const;
    /// Check whether it is safe or not to call GetBioseqs method.
    bool CanGetBioseqs(void) const;
    void ResetBioseqs(void);
    const TBioseqs& GetBioseqs(void) const;
    TBioseqs& SetBioseqs(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CID2S_Chunk_Data_Base(const CID2S_Chunk_Data_Base&);
    CID2S_Chunk_Data_Base& operator=(const CID2S_Chunk_Data_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TId > m_Id;
    CRef< TDescr > m_Descr;
    list< CRef< CSeq_annot > > m_Annots;
    list< CRef< CSeq_align > > m_Assembly;
    list< CRef< CID2S_Sequence_Piece > > m_Seq_map;
    list< CRef< CID2S_Sequence_Piece > > m_Seq_data;
    list< CRef< CBioseq > > m_Bioseqs;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CID2S_Chunk_Data_Base::C_Id::E_Choice CID2S_Chunk_Data_Base::C_Id::Which(void) const
{
    return m_choice;
}

inline
void CID2S_Chunk_Data_Base::C_Id::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CID2S_Chunk_Data_Base::C_Id::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CID2S_Chunk_Data_Base::C_Id::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CID2S_Chunk_Data_Base::C_Id::IsBioseq_set(void) const
{
    return m_choice == e_Bioseq_set;
}

inline
CID2S_Chunk_Data_Base::C_Id::TBioseq_set CID2S_Chunk_Data_Base::C_Id::GetBioseq_set(void) const
{
    CheckSelected(e_Bioseq_set);
    return m_Bioseq_set;
}

inline
CID2S_Chunk_Data_Base::C_Id::TBioseq_set& CID2S_Chunk_Data_Base::C_Id::SetBioseq_set(void)
{
    Select(e_Bioseq_set, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Bioseq_set;
}

inline
void CID2S_Chunk_Data_Base::C_Id::SetBioseq_set(CID2S_Chunk_Data_Base::C_Id::TBioseq_set value)
{
    Select(e_Bioseq_set, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Bioseq_set = value;
}

inline
bool CID2S_Chunk_Data_Base::C_Id::IsGi(void) const
{
    return m_choice == e_Gi;
}

inline
CID2S_Chunk_Data_Base::C_Id::TGi CID2S_Chunk_Data_Base::C_Id::GetGi(void) const
{
    CheckSelected(e_Gi);
    return m_Gi;
}

inline
CID2S_Chunk_Data_Base::C_Id::TGi& CID2S_Chunk_Data_Base::C_Id::SetGi(void)
{
    Select(e_Gi, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Gi;
}

inline
void CID2S_Chunk_Data_Base::C_Id::SetGi(CID2S_Chunk_Data_Base::C_Id::TGi value)
{
    Select(e_Gi, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Gi = value;
}

inline
bool CID2S_Chunk_Data_Base::C_Id::IsSeq_id(void) const
{
    return m_choice == e_Seq_id;
}

inline
bool CID2S_Chunk_Data_Base::IsSetId(void) const
{
    return m_Id.NotEmpty();
}

inline
bool CID2S_Chunk_Data_Base::CanGetId(void) const
{
    return true;
}

inline
const CID2S_Chunk_Data_Base::TId& CID2S_Chunk_Data_Base::GetId(void) const
{
    if ( !m_Id ) {
        const_cast<CID2S_Chunk_Data_Base*>(this)->ResetId();
    }
    return (*m_Id);
}

inline
CID2S_Chunk_Data_Base::TId& CID2S_Chunk_Data_Base::SetId(void)
{
    if ( !m_Id ) {
        ResetId();
    }
    return (*m_Id);
}

inline
bool CID2S_Chunk_Data_Base::IsSetDescr(void) const
{
    return m_Descr.NotEmpty();
}

inline
bool CID2S_Chunk_Data_Base::CanGetDescr(void) const
{
    return IsSetDescr();
}

inline
const CID2S_Chunk_Data_Base::TDescr& CID2S_Chunk_Data_Base::GetDescr(void) const
{
    if (!CanGetDescr()) {
        ThrowUnassigned(1);
    }
    return (*m_Descr);
}

inline
bool CID2S_Chunk_Data_Base::IsSetAnnots(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CID2S_Chunk_Data_Base::CanGetAnnots(void) const
{
    return true;
}

inline
const CID2S_Chunk_Data_Base::TAnnots& CID2S_Chunk_Data_Base::GetAnnots(void) const
{
    return m_Annots;
}

inline
CID2S_Chunk_Data_Base::TAnnots& CID2S_Chunk_Data_Base::SetAnnots(void)
{
    m_set_State[0] |= 0x10;
    return m_Annots;
}

inline
bool CID2S_Chunk_Data_Base::IsSetAssembly(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CID2S_Chunk_Data_Base::CanGetAssembly(void) const
{
    return true;
}

inline
const CID2S_Chunk_Data_Base::TAssembly& CID2S_Chunk_Data_Base::GetAssembly(void) const
{
    return m_Assembly;
}

inline
CID2S_Chunk_Data_Base::TAssembly& CID2S_Chunk_Data_Base::SetAssembly(void)
{
    m_set_State[0] |= 0x40;
    return m_Assembly;
}

inline
bool CID2S_Chunk_Data_Base::IsSetSeq_map(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CID2S_Chunk_Data_Base::CanGetSeq_map(void) const
{
    return true;
}

inline
const CID2S_Chunk_Data_Base::TSeq_map& CID2S_Chunk_Data_Base::GetSeq_map(void) const
{
    return m_Seq_map;
}

inline
CID2S_Chunk_Data_Base::TSeq_map& CID2S_Chunk_Data_Base::SetSeq_map(void)
{
    m_set_State[0] |= 0x100;
    return m_Seq_map;
}

inline
bool CID2S_Chunk_Data_Base::IsSetSeq_data(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CID2S_Chunk_Data_Base::CanGetSeq_data(void) const
{
    return true;
}

inline
const CID2S_Chunk_Data_Base::TSeq_data& CID2S_Chunk_Data_Base::GetSeq_data(void) const
{
    return m_Seq_data;
}

inline
CID2S_Chunk_Data_Base::TSeq_data& CID2S_Chunk_Data_Base::SetSeq_data(void)
{
    m_set_State[0] |= 0x400;
    return m_Seq_data;
}

inline
bool CID2S_Chunk_Data_Base::IsSetBioseqs(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CID2S_Chunk_Data_Base::CanGetBioseqs(void) const
{
    return true;
}

inline
const CID2S_Chunk_Data_Base::TBioseqs& CID2S_Chunk_Data_Base::GetBioseqs(void) const
{
    return m_Bioseqs;
}

inline
CID2S_Chunk_Data_Base::TBioseqs& CID2S_Chunk_Data_Base::SetBioseqs(void)
{
    m_set_State[0] |= 0x1000;
    return m_Bioseqs;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQSPLIT_ID2S_CHUNK_DATA_BASE_HPP
