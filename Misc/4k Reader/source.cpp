class BufferedReader {
    BlockReader* reader;

    uint8_t internal_buffer[FOUR_K];    
    uint32_t internal_buffer_head = 0;
    uint32_t internal_buffer_size = 0; //number of bytes of valid data in internal_buffer

    BufferReader(BlockReader* reader) {
        this->reader = reader;
    }

    uint32_t read_more(uint8_t* buffer, uint32_t num_bytes) {
        int read = 0; //number of bytes copied into buffer

        while (1) { //two scenarios where loop would break: 1. no more data  2. fulfiled request
            if (internal_buffer_head == 0) {
                internal_buffer_size = reader->readmore(internal_buffer); //4096 or less

                if (internal_buffer_size == 0) { //no more bytes to read from data source
                    return read;
                }
            }
            
            int internal_buffer_remains = internal_buffer_size - internal_buffer_head;
            
            if (num_bytes - read >= internal_buffer_remains) { // then put all internal_buffer_remains into buffer
                memcopy(buffer + read, internal_buffer + internal_buffer_head, internal_buffer_remains);
                internal_buffer_head = 0;
                read += internal_buffer_remains;
            } else { //only of some of the the data from internal buffer is needed
                memcopy(buffer + read, internal_buffer + internal_buffer_head, num_bytes - read);
                internal_buffer_head += num_bytes - read;
                read += num_bytes - read;

                return read;
            }
        }
    }
};