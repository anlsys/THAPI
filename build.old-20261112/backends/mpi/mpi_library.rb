require 'ffi'
module FFI

  class MPIStruct < Struct
    def self.enclosing_module
      MPI
    end

    def to_h
      members.zip(values).to_h
    end

    def to_s
      s = "{ "
      s << to_h.each.collect { |k, v|
        if v.kind_of? Array
          "#{k}: [ #{v.join(", ")} ]"
        else
          "#{k}: #{v}"
        end
      }.join(", ")
      s << " }"
      s
    end
  end
  class MPIEnum < Enum
  end
  class MPIUnion < Union
    def self.enclosing_module
      MPI
    end
  end
  class MPIBitmask < Bitmask
    def default=(default)
      @default = default
    end

    def []
      if @default && query.size == 1
        if query[0] == 0
          return @default
        elsif query[0] == @default
          return 0
        end
      end
      super
    end

    def to_native(query, ctx)
      return 0 if query.nil?
      flat_query = [query].flatten
      return 0 if flat_query.size == 1 && query[0] == @default
      super
    end

    def from_native(val, ctx)
      return [@default] if val == 0 && @default
      super
    end
  end
  module Library
    def mpibitmask(*args)
      generic_enum(FFI::MPIBitmask, *args)
    end
    def mpienum(*args)
      generic_enum(FFI::MPIEnum, *args)
    end
  end

  class Struct::InlineArray
    def to_s
      s = "[ "
      s << to_a.join(", ")
      s << " ]"
    end
  end

  class Pointer
    def to_s
      "0x%016x" % address
    end
  end
end
module MPI
  extend FFI::Library

  module Handle
    def to_s
      s = '{ reserved: "'
      s << self[:reserved].to_a.collect { |v| "\\x%02x" % ((v + 256)%256) }.join
      s << '" }'
    end
  end

  module UUID
    def to_s
      a = self[:bytes].to_a.collect { |v| v < 0 ? 0x100 + v : v }
      s = "{ id: "
      s << "%02x" % a[0]
      s << "%02x" % a[1]
      s << "%02x" % a[2]
      s << "%02x" % a[3]
      s << "-"
      s << "%02x" % a[4]
      s << "%02x" % a[5]
      s << "-"
      s << "%02x" % a[6]
      s << "%02x" % a[7]
      s << "-"
      s << "%02x" % a[8]
      s << "%02x" % a[9]
      s << "-"
      s << "%02x" % a[10]
      s << "%02x" % a[11]
      s << "%02x" % a[12]
      s << "%02x" % a[13]
      s << "%02x" % a[14]
      s << "%02x" % a[15]
      s << " }"
    end
  end
  typedef :int, :MPI_Fint
  class MPI_Status < FFI::MPIStruct
    layout :MPI_SOURCE, :int,
           :MPI_TAG, :int,
           :MPI_ERROR, :int,
           :MPI_internal, [ :int, 5 ]
  end
  typedef MPI_Status.by_value, :MPI_Status

  typedef :pointer, :MPI_Op

  typedef :pointer, :MPI_Comm

  typedef :pointer, :MPI_Group

  typedef :pointer, :MPI_Win

  typedef :pointer, :MPI_File

  typedef :pointer, :MPI_Session

  typedef :pointer, :MPI_Message

  typedef :pointer, :MPI_Info

  typedef :pointer, :MPI_Errhandler

  typedef :pointer, :MPI_Request

  typedef :pointer, :MPI_Datatype

  class MPI_F08_status < FFI::MPIStruct
    layout :MPI_SOURCE, :MPI_Fint,
           :MPI_TAG, :MPI_Fint,
           :MPI_ERROR, :MPI_Fint,
           :MPI_internal, [ :MPI_Fint, 5 ]
  end
  typedef MPI_F08_status.by_value, :MPI_F08_status

  typedef :pointer, :MPI_T_enum

  typedef :pointer, :MPI_T_cvar_handle

  typedef :pointer, :MPI_T_pvar_handle

  typedef :pointer, :MPI_T_pvar_session

  typedef :pointer, :MPI_T_event_registration

  typedef :pointer, :MPI_T_event_instance

  MPI_T_cb_safety = mpienum :MPI_T_cb_safety,
    [ :MPI_T_CB_REQUIRE_NONE, 0,
      :MPI_T_CB_REQUIRE_MPI_RESTRICTED, 1,
      :MPI_T_CB_REQUIRE_THREAD_SAFE, 3,
      :MPI_T_CB_REQUIRE_ASYNC_SIGNAL_SAFE, 7 ]

  MPI_T_source_order = mpienum :MPI_T_source_order,
    [ :MPI_T_SOURCE_ORDERED, 1,
      :MPI_T_SOURCE_UNORDERED, 2 ]

end
